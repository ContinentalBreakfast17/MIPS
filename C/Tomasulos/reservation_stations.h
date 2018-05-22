#define RS_LOAD_SZ	5
#define RS_STORE_SZ	5
#define RS_EXE_SZ 	10

typedef struct reservation_station {
	ALU_Data* 			operation;
	RS_Source* 			src_1;
	RS_Source* 			src_2;
	Buffer_Entry* 		buffer_entry;
	Data				val_1;
	Data				val_2;
	char 				busy;
} Station;

typedef struct reservation_stations {
	Station** 			load;
	Station** 			store;
	Station** 			exe;
} Stations;

Stations* 		init_stations();
int 			reserve(Station** stations, Instruction* inst);