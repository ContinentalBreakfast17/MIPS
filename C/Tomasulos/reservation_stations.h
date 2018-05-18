typedef struct reservation_station_source {
	pthread_mutex_t* 	lock;
	pthread_cond_t* 	cond;
	Data 				value;
	int 				sleep_count;
	char 				ready;
} RS_Source;

typedef struct reservation_station {
	ALU_Data* 			operation;
	RS_Source* 			src_1;
	RS_Source* 			src_2;
	Buffer_Entry* 		buffer_entry;
	Data				val_1;
	Data				val_2;
	unsigned int		address;
	char 				busy;
} Station;

RS_Source** 	init_sources();
RS_Source** 	init_f_sources();
Station** 		init_stations(int size);