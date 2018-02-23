typedef struct thread_synch {
	pthread_mutex_t* 	lock;
	pthread_cond_t* 	worker_cond;
	pthread_cond_t* 	control_cond;
	int 				sleep_count;
	int 				alive_count;
} Barrier;

typedef struct branch_detector {
	unsigned int 		address;
	int 				yes;
} Branch;

typedef struct single_thread {
	pthread_t			tid;
	T_Data* 			data;	
} Thread;

typedef struct thread_queue {
	Thread* 			threads;
	int 				capacity;
	int 				count;
	int 				front;
} T_Queue;

typedef struct thread_data {
	T_Queue* 			thread_queue;
	P_Regs* 			interstage_regs;
	P_Regs* 			tmp_interstage_regs
	Branch* 			branch;
	ALU_Data*			alu_data;
	Barrier* 			barrier;
	int* 				regs;
	int* 				f_regs;
	unsigned char* 		memory;
	unsigned int 		pc;
	int 				id;
	int 				done;
	int 				stage;
} T_Data;

Barrier* new_barrier();
void new_worker(Barrier* barrier);
void wait_worker(Barrier* barrier);
void kill_worker(Barrier* barrier);
void wait_control(Barrier* barrier);

Branch* new_branch_detector();

T_Queue* new_thread_queue();
void free_queue(T_Queue* queue);
int enqueue(T_Queue* queue, pthread_t id, T_Data* data);
Thread* dequeue(T_Queue* queue);
Thread* dequeue_back(T_Queue* queue);
Thread* peek(T_Queue* queue);
Thread* peek_back(T_Queue* queue);

T_Data* new_data(T_Queue* queue, Barrier* barrier, P_Regs* interstage_regs, P_Regs* tmp_interstage_regs, Branch* branch, Hardware* hardware);