/*
	Allocates memory for data memory
*/
unsigned char* init_memory() {
	unsigned char* data_memory = (unsigned char*)malloc(MEM_SIZE);
	check_alloc((void*)data_memory);
	return data_memory;
}

/*
	Get the direction of the memory operation according to its alignment, either 1 or -1
*/
int get_direction(unsigned int alignment) {
	return (alignment == MEM_ALIGN_RIGHT) ? (-1) : (1);
}

/*
	Determines whether or not a given address is in a valid range
*/
int in_data_range(unsigned int address, unsigned int size, unsigned int alignment) {
	int dir = get_direction(alignment);
    unsigned int end = address + size*dir - 1*dir;
    if((address < INIT_GP || address >= MEM_SIZE) && (end < INIT_GP || end >= MEM_SIZE))
        return 0;
    return 1;
}

/*
	Determines whether an address is at the proper alignment for the memory operation
*/
int good_alignment(unsigned int address, unsigned int size, unsigned int alignment) {
	return !(alignment == MEM_ALIGN_FORCE && (address % size) != 0);
}

/*
	Rights the data to the value pointer
*/
int load_data(unsigned char* memory, unsigned int address, unsigned long long* value, unsigned int size, unsigned int alignment, unsigned int extend_sign) {
    // make sure the address is in valid data range and aligns with the data type
    // TODO: use error codes
    if(!in_data_range(address, size, alignment) || !good_alignment(address, size, alignment)) return 1;

    int i = 0;
    int direction = get_direction(alignment);
    do {
        int shftamt = (direction == -1) ? (i) : (size-1-i);
        *((char*)value + shftamt) = memory[address+i*direction];
        i++;
    } while((i % size) != 0);

    if(extend_sign && (*value >> (unsigned int)(size*8 - 1))) {
    	*value = *value | (0xffffffff - (1 << (size*8 - 1)));
    }

    return 0;
}

/*
    Stores the data according to the parameters
*/
int store_data(unsigned char* memory, unsigned int address, unsigned long long value, unsigned int size, unsigned int alignment) {
    // make sure the address is in valid data range and aligns with the data type
    // TODO: use error codes
    if(!in_data_range(address, size, alignment) || !good_alignment(address, size, alignment)) return 1;
    
    int i = 0;
    int direction = get_direction(alignment);
    do {
        int shftamt = (direction == -1) ? (i*8) : ((size-1-i)*8);
        memory[address + i*direction] = (value >> shftamt) & 0xff;
        i++;
    } while((i % size) != 0);

    return 0;
}