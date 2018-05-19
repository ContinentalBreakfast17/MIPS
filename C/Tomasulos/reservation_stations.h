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
	Station** 			list;
	int 				size;
} Stations;

Stations* 		new_stations(int size);
int 			reserve(Station** stations, Instruction* inst);