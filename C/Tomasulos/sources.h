typedef struct reservation_station_source {
	pthread_mutex_t* 	lock;
	pthread_cond_t* 	cond;
	Data 				value;
	int 				sleep_count;
	unsigned char 		id;
	char 				ready;
} RS_Source;

typedef struct reservation_station_memory_sources {
	
} RS_Mem_Sources;

typedef struct  reservation_station_sources {
	RS_Source** 		regs;
	RS_Source** 		f_regs;
	RS_Mem_Sources* 	mem;
} RS_Sources;

RS_Sources* 	init_sources(int size);