/*
	Initializes a new source
*/
RS_Source* new_source(int index) {
	RS_Source* source = (RS_Source*)malloc(sizeof(RS_Source));
	check_alloc((void*)source);
	source->sleep_count = 0;
	source->ready = 0;
	source->index = index;
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
		sources[i] = NULL;
	}
	return sources;
}

/*
	Initializes a new memory source
*/
RS_Mem_Source* new_mem_source() {
	RS_Mem_Source* source = (RS_Mem_Source*)malloc(sizeof(RS_Mem_Source));
	check_alloc((void*)source);
	source->address = new_source(0);
	source->access = new_source(0);
	return source;	
}

/*
	Initializes the memory sources queue
*/
RS_Mem_Sources* init_mem_sources(int capacity) {
	RS_Mem_Sources* sources = (RS_Mem_Sources*)malloc(sizeof(RS_Mem_Sources));
	check_alloc((void*)sources);
	sources->queue = (RS_Mem_Source**)malloc(sizeof(RS_Mem_Source*)*capacity);
	check_alloc((void*)sources->queue);
	sources->front = 0;
	sources->count = 0;
	sources->capacity = capacity;
	return sources;
}

/*
	Initializes all the sources needed
	Capacity should be same as in ROB
*/
RS_Sources* init_sources(int capacity) {
	RS_Sources* sources = (RS_Sources*)malloc(sizeof(RS_Sources));
	check_alloc((void*)sources);
	sources->regs = new_sources(34); // 34 for lo and hi
	sources->f_regs = new_sources(32);
	sources->mem = init_mem_sources(capacity);
	return sources;
}

/*
	Creates a new source and places it in the sources list at the given index
	The index should be in the rage of the size of the sources, e.g. 0-33 for int regs and 0-31 for float regs
	Not for use with mem sources
*/
RS_Source* spawn_source(RS_Source** sources, int index) {
	return sources[index] = new_source(index);
}

/*
	Returns the source at the index
	The index should be in the rage of the size of the sources, e.g. 0-33 for int regs and 0-31 for float regs
	Not for use with mem sources
*/
RS_Source* get_source(RS_Source** sources, int index) {
	return sources[index];
}

/*
	Removes the source from the source list (if present) and frees it
	Does nothing if any instructions are still waiting on the result
	Not for use with mem sources
*/
void destroy_source(RS_Source** sources, RS_Source* source) {
	if(source->sleep_count > 0) return;
	if(sources[source->index] == source) {
		sources[source->index] = NULL;
	}
	check_result(pthread_mutex_destroy(source->lock));
	check_result(pthread_cond_destroy(source->cond));
	free(source);
}

/*
	Adds a new memory source to the end of the queue and returns it
	Returns NULL if queue is full
	Call when moving a memory instruction to the reservation station
*/
RS_Mem_Source* spawn_mem_source(RS_Mem_Sources* sources, unsigned int address, int size, char type) {
	if(sources->count == sources->capacity) return NULL;
	RS_Mem_Source* source = new_mem_source();
	source->start = address;
	source->end = address + size - 1;
	source->type = type;
	sources->queue[(sources->front + sources->count) % sources->capacity] = source;
	sources->count++;
	return source;
}