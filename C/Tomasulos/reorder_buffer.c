/*
	Initializes the reorder buffer
*/
Reorder_Buffer* init_reorder_buffer(int capacity) {
	Reorder_Buffer* buffer = (Reorder_Buffer*)malloc(sizeof(Reorder_Buffer));
	check_alloc((void*)buffer);
	buffer->queue = (Buffer_Entry**)malloc(sizeof(Buffer_Entry*)*capacity);
	check_alloc((void*)buffer->queue);
	buffer->capacity = capacity;
	buffer->count = 0;
	buffer->front = 0;
	return buffer;
}

/*
	Checks whether or not the buffer is at capacity
*/
char is_full(Reorder_Buffer* buffer) {
	return buffer->size == buffer->capacity;
}

/*
	Adds a new entry to the back of the list and returns it
*/
Buffer_Entry* new_buffer_entry(Reorder_Buffer* buffer) {
	if(is_full(buffer)) return NULL;

	Buffer_Entry* entry = (Buffer_Entry*)malloc(sizeof(Buffer_Entry));
	check_alloc((void*)entry);
	entry->ready = 0;
	entry->exception = 0;

	buffer->queue[(buffer->front + buffer->count) % buffer->capacity] = entry;
	buffer->count++;
	return entry;
}

/*
	Tries to commit the front of the queue and remove it, if the front is not ready then do nothing
*/
void commit_front(Reorder_Buffer* buffer) {
	Buffer_Entry* entry = buffer->queue[buffer->front];
	if(entry->ready) {
		// TODO: actually handle exceptions
		if(entry->exception) {
			printf("Exception %d\n", entry->exception);
			exit(entry->exception);
		}

		// store result of store/register

		// check mispredicted branch (flush buffer if so)

		// remove entry
	}
}

/*
	Marks an entry as ready to commit
*/
void mark_ready(Buffer_Entry* entry) {
	entry->ready = 1;
}