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
unsigned int get_pc(PC* program_counter) {
	return program_counter->counter;
}

/*
	Increments the program counter by {val}
	Exits if value is not valid
*/
int advance_pc(PC* program_counter, int val) {
	int new_counter = program_counter->counter + val;
	if(new_counter < 0x04000000 || new_counter >= 0x10000000)
		return -1;
	program_counter->counter = new_counter;
	return 0;
}

/*
	Sets the program counter to {address}
	Exits if value is not valid
*/
int set_pc(PC* program_counter, unsigned int address) {
	if(address < 0x04000000 || address >= 0x10000000)
		return -1;
	program_counter->counter = address;
	return 0;
}

/*
	Frees the program counter
*/
void free_pc(PC* program_counter) {
	free(program_counter);
}