typedef struct reservation_station_source {
	pthread_mutex_t* 	lock;
	pthread_cond_t* 	cond;
	Data 				value;
	int 				sleep_count;
	int 				id;
	char 				ready;
} RS_Source;

typedef struct reservation_station_memory_source {
	RS_Source* 			address;
	RS_Source* 			access;
	unsigned int 		start;
	unsigned int 		end;
} RS_Mem_Source;

typedef struct reservation_station_memory_sources {
	RS_Mem_Source* 		queue;
	int 				capacity;
	int 				front;
	int 				count;
} RS_Mem_Sources;

typedef struct  reservation_station_sources {
	RS_Source** 		regs;
	RS_Source** 		f_regs;
	RS_Mem_Sources* 	mem;
} RS_Sources;

RS_Sources* 	init_sources(int size);
RS_Source* 		spawn_source(RS_Sources* sources, int index);
void 			destroy_source(RS_Sources* sources, RS_Source* source);
RS_Source* 		get_source(RS_Source** sources, int index);
RS_Mem_Source* 	spawn_mem_source(RS_Mem_Sources* sources, unsigned int address, int size, char type);