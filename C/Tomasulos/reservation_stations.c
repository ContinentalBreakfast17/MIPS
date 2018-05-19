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
Stations* new_stations(int size) {
	Stations* stations = (Stations*)malloc(sizeof(Stations));
	check_alloc((void*)stations);
	stations->list = (Station**)malloc(sizeof(Station*)*size);
	check_alloc((void*)stations->list);
	int i;
	for(i = 0; i < size; i++) {
		stations->list[i] = new_station();
	}
	return stations;
}

/*
	Returns the first free station or NULL if none are available
*/
Station* find_free_station(Stations* stations) {
	int i;
	for(i = 0; i < stations->size; i++) {
		if(!stations->list[i]->busy) {
			return stations->list[i];
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

	station->src_1 = ;
	station->src_2 = ;

}