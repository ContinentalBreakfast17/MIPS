/*
	Initializes a new source
*/
RS_Source* new_source(int id) {
	RS_Source* source = (RS_Source*)malloc(sizeof(RS_Source));
	check_alloc((void*)source);
	source->sleep_count = 0;
	source->ready = 0;
	source->id = id;
	pthread_mutex_t lock;
	pthread_cond_t cond;
	check_result(pthread_mutex_init(&lock, NULL));
	check_result(pthread_cond_init(&cond, NULL));
	source->lock = &lock;
	source->cond = &cond;
	return source;
}

/*
	Initializes sources for the given size, intended for use for both integer and floating point sources
*/
RS_Source** new_sources(int size) {
	RS_Source** sources = (RS_Source**)malloc(sizeof(RS_Source*)*size);
	check_alloc((void*)sources);
	int i;
	for(i = 0; i < size; i++) {
		sources[i] = new_source(i);
	}
	return sources;
}

/*
	Initializes all the sources needed
*/
RS_Sources* init_sources() {
	
}