/*
	Creates a new buffer destination
*/
Buffer_Dest* new_destination() {
	Buffer_Dest* dest = (Buffer_Dest*)malloc(sizeof(Buffer_Dest));
	check_alloc((void*)dest);
	dest->address_calc = 0;
	dest->fp = 0;
	dest->mem_alignment = MEM_ALIGN_FORCE;
	return dest;
}

/*
	Creates a new buffer entry
*/
Buffer_Entry* new_buffer_entry() {
	Buffer_Entry* entry = (Buffer_Entry*)malloc(sizeof(Buffer_Entry));
	check_alloc((void*)entry);
	entry->dest = new_destination();
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
		if(entry->type == ROB_STORE) {
			store_data(hardware->memory, entry->dest->address, entry->value.i, entry->dest->size, entry->dest->mem_alignment);
		} else if(entry->type == ROB_WR) { 
			set_reg(hardware->registers, entry->dest->reg_type, entry->dest->size, entry->value);	
		}

		// TODO: check mispredicted branch (flush buffer if so)
		if(entry->type == ROB_BRANCH) {

		}

		// remove entry
		clear_register_file(hardware->reg_file, entry);
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

/*
	Returns true if a load instruction can calculate its address
	A load instruction cannot calculate its address if any previous stores have not calculated their address
*/
int can_calculate_address(Reorder_Buffer* buffer, Buffer_Entry* this) {
	int i = buffer->front;
	while(buffer->queue[i] != this) {
		if((buffer->queue[i]->type & ROB_STORE) && !buffer->queue[i]->dest->address_calc) {
			return false;
		}
		i = (i + 1) % buffer->capacity;
	}
	return true;
}

/*
	Returns true if a load instruction can access memory
	A load instruction can access memory once there are no previous stores accessing the same memory
*/
int can_access_memory(Reorder_Buffer* buffer, Buffer_Entry* this) {
	int i = buffer->front;
	unsigned int this_first = this->dest->address;
	unsigned int this_last = this->dest->address + this->dest->size - 1;

	while(buffer->queue[i] != this) {
		Buffer_Entry* entry = buffer->queue[i];
		unsigned int first = entry->dest->address;
		unsigned int last = entry->dest->address + entry->dest->size - 1;

		int intersect = (start >= this_start && start <= this_last) || (last >= this_start && last <= this_last);
		if((entry->type & ROB_STORE) && intersect) {
			return false;
		}

		i = (i + 1) % buffer->capacity;
	}

	return true;
}