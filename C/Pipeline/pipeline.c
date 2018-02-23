void* run_thread(void* arg);

/*
	Spawns a new thread with the given data and adds it to the queue
*/
int new_thread(T_Queue* queue, T_Data* data) {
	pthread_t thread;
	int create = pthread_create(&thread, NULL, (void*(*)(void*))run_thread, (void*)data);
	if(create != 0) {
		printf("Error spawning new thread\n");
		exit(1);
	}
	return data->id = enqueue(queue, thread, data);
}

/*
	The main juice of the program
*/
int run(Hardware* hardware) {
	// Initialize pipeline stuff
	T_Queue* queue = new_thread_queue();
	P_Regs* interstage_regs = init_interstage_regs();
	P_Regs* tmp_interstage_regs = init_interstage_regs();
	Branch* branch = new_branch_detector();
	Barrier* barrier = new_barrier();
	while(1) {
		// create new thread and add to queue (if there is room and the pipeline is not frozen) (or, if nothing in pipeline, create a new thread [preventing null/invalid pointer stuff])
		if(queue->count == 0 || (queue->count < queue->capacity && !(peek_back(queue)->data->stage == STAGE_IF))) {
			T_Data* data = new_data(queue, barrier, interstage_regs, tmp_interstage_regs, branch, hardware);
			new_thread(queue, data);
		} 
		
		// wait twice (with sleeps to simulate clock)
		usleep(100);
		wait_control(barrier);
		usleep(100);
		wait_control(barrier);

		// copy back results
		copy_interstage_regs(interstage_regs, tmp_interstage_regs);

		// check branch/advance pc
		int bad_pc = 0;
		if(branch->yes) {
			bad_pc = set_pc(hardware->program_counter, branch->address);
			flush_instruction(queue);
			branch->yes = 0;
		} else {
			bad_pc = advance_pc(hardware->program_counter, 4); // DON'T DO IF STALLED
		}
		if(bad_pc) {
			printf("Bad program counter\n");
			exit(1);
		}

		// check dead threads
		reap_instructions(queue, hardware);

		// Need another write to make sure write backs happen in synch
		wait_control(barrier);
	}
}

/*
	The path of each instruction
*/
void* run_thread(void* arg) {
	T_Data* this = (T_Data*)arg;
	int(*pipeline_funcs[5])(T_Data*, P_Regs*) = {fetch_instruction, decode_instruction, execute_instruction, memory_instruction, write_back_instruction};
	int os;
	while(1) {
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &os);
		int result = 0, wb = this->stage == STAGE_WB;

		if(wb)
			result = (*pipeline_funcs[this->stage])(this);
		wait_worker(this->barrier); // clock up
		
		clear_hazards(this); // wait until hazards are cleared

		if(!wb)
			result = (*pipeline_funcs[this->stage])(this);
		wait_worker(this->barrier); // clock down
		
		// check result
		if(result != 0) {
			this->done = result;
			kill_worker(this->barrier);
			pthread_exit(NULL);
		}

		if(wb) {
			this->done = NORMAL_EXIT;
			kill_worker(this->barrier);
			pthread_exit(NULL);
		} else
			this->stage++;

		// Wait for thread synchronization
		wait_worker(this->barrier);

		// Check for death signal
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &os);
		pthread_cleanup_push(kill_worker, this->barrier);
		pthread_testcancel();
		pthread_cleanup_pop(0);
	}
}

/*
	Handles dead threads due to terminated instructions
	Only operates on dead threads
*/
void reap_instructions(T_Queue* queue, Hardware* hardware) {
	int i;
	for(i = 0; i < queue->count; i++) {
		int index = (i+queue->front)%queue->capacity;
		int done = queue->threads[index]->data->done;
		if(done) {
			int join = pthread_join(queue->threads[index]->data->tid, NULL);
			if(join != 0) {
				printf("Error joining thread\n");
				return -1;
			}
			// check exit code
			if(done == NORMAL_EXIT) {
				// Normal exit means the thread will be at the front of the queue
				Thread* dead_thread = dequeue(queue);
				free(thread->data);
				free(thread);
			} else {
				handle_exception(queue->threads[index], hardware, done);
			}
		}
	}
}

/*
	This flushes bad instructions from the queue
	Needed because pipeline assumes branch not taken, so when branch is taken there is a bad instruction in the IF stage
	This instruction can always be found at the back of the queue
	Also note that since it is dequeued we will never reap this instruction
*/
int flush_instruction(T_Queue* queue) {
	Thread* thread = dequeue_back(queue);
	int result = pthread_cancel(thread->tid);
	free_data(thread->data);
	free(thread);
	return result;
}

/*
	Flushes the remaining threads
*/
void shutdown(T_Queue* queue, Branch* branch, P_Regs* interstage_regs, P_Regs* tmp_interstage_regs, Barrier* barrier) {
	free_queue(queue);
	free_interstage_regs(interstage_regs);
	free_interstage_regs(tmp_interstage_regs);
	free_barrier(barrier);
	free(branch);
}

/*
	Stalls for n cycles
*/
void wait(T_Data* this, int n) {
	int i;
	for(i = 0; i < n; i++) {
		wait_worker(this->barrier);
		wait_worker(this->barrier);
	}
}

/*
	Fetches the instruction at the program counter of the instruction
	Writes back to P_IF of the temporary interstage registers if successful
	Returns error if the program counter is invalid
*/
int fetch_instruction(T_Data* this) {
	unsigned int inst = get_instruction(this->memory, this->pc);
	if(inst < 0)
		return BAD_PC_IF;
	this->tmp_interstage_regs->p_if->inst = inst;
	return 0;
}

/*
	Details found in decipher_instruction in instruction.c
*/
int decode_instruction(T_Data* this) {
	return decipher_instruction(this->interstage_regs->inst, this->tmp_interstage_regs, this->alu_data, this->branch);
} 

/*
	Executes the instruction as described by the alu_data of the thread
	Writes back to P_EXE of the temporary interstage registers if successful
	Returns error if the alu returns an error
*/
int execute_instruction(T_Data* this) {
	P_ID* id = this->interstage_regs->p_id;
	P_EXE* exe = this->tmp_interstage_regs->p_exe;

	int result = 0;
	if(this->interstage_regs->p_id->fp_op)
		result = f_compute();
	else
		result = compute();
	if(result != 0) return result;

	exe->alu_result = (unsigned int)this->alu_data->retval.i;
	exe->data_2 = id->data_2;
	exe->mem_op_sz = id->mem_op_sz;
	exe->rd = id->rd;
	exe->mem_rd = id->mem_rd;
	exe->mem_wr = id->mem_wr;
	exe->reg_wr = id->reg_wr;
	exe->fp_wr = id->fp_wr;
	return 0;
}

/*
	Accesses data memory as described by the P_EXE interstage register
	Writes back to P_MEM of the temporary interstage registers if successful
	Returns an error if memory address is invalid
*/
int memory_instruction(T_Data* this) {
	P_EXE* exe = this->interstage_regs->p_exe;
	P_MEM* mem = this->tmp_interstage_regs->mem;
	int(*store_funcs[3])(unsigned char*, unsigned int, void*) = {store_byte, store_half, store_word};
	int(*load_funcs[3])(unsigned char*, unsigned int, void*) = {load_byte, load_half, load_word};
	int result = 0;
	unsigned int retval = 0;

	if(exe->mem_wr) {
		result = (*store_funcs[exe->mem_op_sz])(this->memory, this->alu_result, this->data_2);
	} else if(exe->mem_rd) {
		result = (*load_funcs[exe->mem_op_sz])(this->memory, this->alu_result, (void*)&retval);
	}
	if(result != 0) return result;
	
	if(exe->mem_rd) mem->mem_data = retval;
	mem->alu_result = exe->alu_result;
	mem->rd = exe->rd;
	mem->mem_rd = exe->mem_rd;
	mem->reg_wr = exe->reg_wr;
	mem->fp_wr = exe->fp_wr;
	return 0;
}

/*
	Writes the result of the instruction back to the destination register, if applicable
	This operation cannot fail
*/
int write_back_instruction(T_Data* this) {
	P_MEM* mem = this->interstage_regs->p_mem;
	unsigned int wr_data = (mem->mem_rd) ? (mem->mem_data) : (mem->alu_result);
	if(mem->reg_wr && mem->fp_wr)
		set_reg(this->f_regs, mem->rd, (float)wr_data);
	else if(mem->reg_wr)
		set_reg(this->regs, mem->rd, wr_data);
	return 0;
}

// probably move branch stuff to separate directory
is_branch();
resolve_branch();