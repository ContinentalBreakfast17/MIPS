/*
	Initializes a new station
*/
Station* new_station(int size) {
	Station* station = (Station*)malloc(sizeof(Station));
	check_alloc((void*)station);
	station->busy = 0;
	return station;
}

/*
	Initializes the specified number of reservation stations
*/
Station** new_stations_list(int size) {
	Stations** stations = (Stations**)malloc(sizeof(Station*));
	check_alloc((void*)stations);
	int i;
	for(i = 0; i < size; i++) {
		stations[i] = new_station();
	}
	return stations;
}

/*
	Initializes all reservation stations
*/
Stations* init_stations() {
	Stations* stations = (Stations*)malloc(sizeof(Stations));
	check_alloc((void*)stations);
	stations->load = new_stations_list(RS_LOAD_SZ);
	stations->store = new_stations_list(RS_STORE_SZ);
	stations->exe = new_stations_list(RS_EXE_SZ);
	return stations;
}

/*
	Returns the first free station or NULL if none are available
*/
Station* find_free_station(Stations* stations, int type) {
	Station** station_list;
	int size;
	switch(type) {
		case LOAD:
			station_list = stations->load;
			size = RS_LOAD_SZ;
			break;
		case STORE:
			station_list = stations->store;
			size = RS_STORE_SZ;
			break;
		case EXE:
			station_list = stations->exe;
			size = RS_EXE_SZ;
			break;
	}

	int i;
	for(i = 0; i < size; i++) {
		if(!stations_list[i]->busy) {
			return stations_list[i];
		}
	}
	return NULL;
}

/*
	Tries to reserve a station for the instruction
*/
int reserve(Stations* stations, Instruction* inst, RS_Source* sources, RS_Source* f_sources, RS_Mem_Sources* mem_sources) {
	Station* station = find_free_station(stations);
	// return nonzero reponse to indicate no free stations
	if(station == NULL) return 1;

	station->busy = 1;
	station->src_1 = ;
	station->src_2 = ;

}