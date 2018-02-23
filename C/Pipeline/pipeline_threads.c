/*
	Creates a new thread synchronization unit
*/
Barrier* new_barrier() {
	Barrier* barrier = (Barrier*)malloc(sizeof(Barrier));
	check_alloc((void*)barrier);

	barrier->lock = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	check_alloc((void*)barrier->lock);
	int init = pthread_mutex_init(barrier->lock, 0);
	if(init != 0) {
		printf("Error initiating barrier mutex\n");
		exit(1);
	}

	barrier->worker_cond = (pthread_cond_t*)malloc(sizeof(pthread_cond_t));
	check_alloc((void*)barrier->worker_cond);
	barrier->control_cond = (pthread_cond_t*)malloc(sizeof(pthread_cond_t));
	check_alloc((void*)barrier->control_cond);
	int init1 = pthread_cond_init(barrier->worker_cond, NULL);
	int init2 = pthread_cond_init(barrier->control_cond, NULL);
	if((init1 | init2) != 0) {
		printf("Error initiating barrier wait condtions\n");
		exit(1);
	}

	barrier->sleep_count = 0;
	barrier->alive_count = 0;
	return barrier;
}

/*
	Increments alive count to signify the creation of a new worker
*/
void new_worker(Barrier* barrier) {
	while(pthread_mutex_trylock(barrier->lock));
	barrier->alive_count++;
	pthread_mutex_unlock(barrier->lock);
}

/*
	Increments sleep count and waits
*/
void wait_worker(Barrier* barrier) {
	while(pthread_mutex_trylock(barrier->lock));
	barrier->sleep_count++;
	if(barrier->sleep_count == barrier->alive_count) pthread_cond_signal(barrier->control_cond);
	pthread_cond_wait(barrier->worker_cond);
	pthread_mutex_unlock(barrier->lock);
}

/*
	Decrements the alive count to signal the death of a worker
*/
void kill_worker(Barrier* barrier) {
	while(pthread_mutex_trylock(barrier->lock));
	barrier->alive_count--;
	pthread_mutex_unlock(barrier->lock);
}

/*
	Waits on all the alive threads to wait, then wakes them up
*/
void wait_control(Barrier* barrier) {
	while(pthread_mutex_trylock(barrier->lock));
	while(barrier->sleep_count != barrier->alive_count)
		pthread_cond_wait(barrier->control_cond);
	barrier->sleep_count = 0;
	pthread_cond_broadcast(barrier->worker_cond);
	pthread_mutex_unlock(barrier->lock);
}

/*
	Frees the barrier
*/
void free_barrier(Barrier* barrier) {
	pthread_cond_destroy(barrier->worker_cond);
	pthread_cond_destroy(barrier->control_cond);
	pthread_mutex_destroy(barrier->lock);
	free(barrier->worker_cond);
	free(barrier->control_cond);
	free(barrier->lock);
	free(barrier);
}

/*
	Initializes a struct which contains details on current branch instructions
	Branches are predicted not taken and resolved in ID stage
*/
void new_branch_detector() {
	Branch* branch = (Branch*)malloc(sizeof(Branch));
	check_alloc((void*)branch);
	branch->yes = 0;
	return branch;
}
	

/* 
	Creates a new queue to contain thread ID's
*/
T_Queue* new_thread_queue() {
	T_Queue* queue = (T_Queue*)malloc(sizeof(T_Queue));
	check_alloc((void*)queue);
	queue->threads = (pthread_t*)malloc(sizeof(pthread_t)*5);
	check_alloc((void*)queue->threads);
	queue->capacity = 5;
	queue->count = 0;
	queue->front = 0;
	return queue;
}

/*
	Frees all entries in the queue, then frees the queue itself
*/
void free_queue(T_Queue* queue) {
	while(queue->count > 0) {
		Thread* thread = dequeue(queue);
		free_data(thread->data);
		free(thread);
	}
	free(queue->threads);
	free(queue);
}

/*
	Adds a new thread id to the end of the queue and returns the index of the new entry
*/
int enqueue(T_Queue* queue, pthread_t id, T_Data* data) {
	Thread* thread = (Thread*)malloc(sizeof(Thread));
	check_alloc((void*)thread);
	thread->data = data;
	thread->tid = thread;
	thread->data->done = 0;
	int index = (queue->front+queue->count)%queue->capacity;
	queue->threads[index] = thread;
	queue->count++;
	return index;
}

/*
	Removes and returns the front of the queue
*/
Thread* dequeue(T_Queue* queue) {
	if(queue->count <= 0) return -1;
	Thread* thread = queue->threads[queue->front++];
	queue->count--;
	return thread;
}

/*
	Removes and returns the back of the queue
*/
Thread* dequeue_back(T_Queue* queue) {
	if(Thread*->count <= 0) return -1;
	pthread_t thread = queue->threads[(queue->front+queue->count-1)%queue->capacity];
	queue->count--;
	return thread;
}


/* 
	Returns the thread at the front of the queue
*/
Thread* peek(T_Queue* queue) {
	return queue->threads[queue->front];
}

/*
	Returns the thread at the back of the queue
*/
Thread* peek_back(T_Queue* queue) {
	return queue->threads[(queue->front+queue->count-1)%queue->capacity];
}

/*
	Creates a pointer to new thread data with the given parameters
	Thread id needs to be added once the thread is created
*/
T_Data* new_data(T_Queue* queue, pthread_barrier_t* barrier, P_Regs* interstage_regs, Branch* branch, Hardware* hardware) {
	T_Data* data = (T_Data*)malloc(sizeof(T_Data));
	check_alloc((void*)data);
	data->thread_queue = queue;
	data->interstage_regs = interstage_regs;
	data->branch = branch;
	data->barrier = barrier;
	data->alu_data = (ALU_Data*)malloc(sizeof(ALU_Data));
	check_alloc((void*)data->alu_data);
	data->regs = hardware->registers;
	data->f_regs = hardware->f_registers;
	data->memory = hardware->memory;
	data->pc = get_pc(hardware->program_counter);
	data->stage = STAGE_IF;
	data->done = 0;
	return data;
}

void free_data(T_Data* data) {
	free(data->alu_data);
	free(data);
}