Buffer_Entry* new_buffer_entry() {
	Buffer_Entry* entry = (Buffer_Entry*)malloc(sizeof(Buffer_Entry));
	check_alloc((void*)entry);
	entry->ready = 0;
	entry->exception = 0;
	return entry;
}

/*
	Frees the buffer entry
*/
void free_buffer_entry(Buffer_Entry* entry) {
	free(entry->dest);
	free(entry);
}

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
Buffer_Entry* add_buffer_entry(Reorder_Buffer* buffer) {
	if(is_full(buffer)) return NULL;
	buffer->queue[(buffer->front + buffer->count) % buffer->capacity] = new_buffer_entry;
	buffer->count++;
	return entry;
}

/*
	Removes and returns the front of the buffer
*/
Buffer_Entry* dequeue_buffer(Reorder_Buffer* buffer) {
	Buffer_Entry* entry = buffer->queue[buffer->front];
	buffer->front = (buffer->front + 1) % buffer->capacity;
	buffer->count--;
	return entry;
}

/*
	Removes and frees all entries in the buffer
*/
void flush_buffer(Reorder_Buffer* buffer) {
	while(buffer->count > 0) {
		Buffer_Entry* entry = dequeue_buffer(buffer);
		free_buffer_entry(entry);
	}
}

/*
	Frees the buffer
*/
void free_buffer(Reorder_Buffer* buffer) {
	flush_buffer(buffer);
	free(buffer->queue);
	free(buffer);
}

/*
	Tries to commit the front of the queue and remove it, if the front is not ready then do nothing
*/
void commit_front(Reorder_Buffer* buffer, Hardware* hardware) {
	Buffer_Entry* entry = buffer->queue[buffer->front];
	if(entry->ready) {
		// TODO: actually handle exceptions
		handle_exception(entry);

		// store result of store/register
		if(entry->type & ROB_STORE) {
			entry->exception = store_data(hardware->memory, entry->dest->address, entry->value.i, entry->dest->size, entry->dest->mem_alignment);
		} else if((entry->type & ROB_WR) && entry->dest->fp) { 
			entry->exception = set_f_reg(hardware->f_registers, entry->dest->reg, entry->value.f, entry->dest->size);
		} else if(entry->type & ROB_WR) {
			entry->exception = set_reg(hardware->registers, entry->dest->reg, entry->value.i, entry->dest->size);
		}
		handle_exception(entry);	

		// TODO: check mispredicted branch (flush buffer if so)

		// remove entry
		dequeue_buffer(buffer);
		free_buffer_entry(entry);
	}
}

/*
	Marks an entry as ready to commit
*/
void mark_ready(Buffer_Entry* entry) {
	entry->ready = 1;
}