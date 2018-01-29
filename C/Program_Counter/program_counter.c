/*
	Initializes program counter to the given entry point
*/
PC* init_pc(unsigned int entry_point) {
	PC* program_counter = (PC*)malloc(sizeof(PC));
	check_alloc((void*)program_counter);
	program_counter->counter = entry_point;
	program_counter->entry_point = entry_point;
	return program_counter;
}

/*
	Returns the counter value
*/
int get_pc(PC* program_counter) {
	return program_counter->counter;
}

/*
	Increments the program counter by {val}
*/
int advance_pc(PC* program_counter, int val) {
	return program_counter->counter += val;
}

/*
	Sets the program counter to {address}
*/
int set_pc(PC* program_counter, unsigned int address) {
	return program_counter->counter = address;
}