/*
	Allocates memory for data memory
*/
unsigned char* init_memory() {
	unsigned char* data_memory = (unsigned char*)malloc(MEM_SIZE);
	check_alloc((void*)data_memory);
	return data_memory;
}

/*
	Determines whether or not a given address is in a valid range
*/
int in_data_range(int address) {
	if(address < INIT_GP || address >= MEM_SIZE)
		return 0;
	return 1;
}

/*
	Determines whether an address is suitable by checking alignment and checking if the address is valid
*/
int good_address(int address, int alignment) {
	if(address % alignment != 0 || !in_data_range(address)) {
		printf("Bad data alignment\n");
		exit(1);
	}
	return 1;
}

/*
	Returns the an unsigned int made of the 4 bytes starting from the given address (first byte is MSB)
*/
unsigned int load_word(unsigned char* data_memory, unsigned int address) {
	if(good_address(address, sizeof(int))) {
		unsigned int r, i;
		for(i = 0; i < sizeof(int); i++) {
			*((char*)&r + (sizeof(int)-1 - i)) = data_memory[address+i];
		}
		return r;
	}
}

/*
	Returns the an unsigned short made of the 2 bytes starting from the given address (first byte is MSB)
*/
unsigned short load_half(unsigned char* data_memory, unsigned int address) {
	if(good_address(address, sizeof(short))) {
		int i;
		unsigned short r;
		for(i = 0; i < sizeof(short); i++) {
			*((char*)&r + (sizeof(short)-1 - i)) = data_memory[address+i];
		}
		return r;
	}
}

/*
	Returns the unsigned byte at the given address
*/
unsigned char load_byte(unsigned char* data_memory, unsigned int address) {
	if(good_address(address, sizeof(char))) {
		return data_memory[address];
	}
}

/*
	Stores the given int at the address (first byte is MSB)
*/
void store_word(unsigned char* data_memory, unsigned int address, unsigned int value) {
	if(good_address(address, sizeof(int))) {
		int i;
		for(i = 0; i < sizeof(int); i++)
			data_memory[address+i] = (value >> (sizeof(int)-1-i)*8) & 0xff;
	}
}

/*
	Stores the given short at the address (first byte is MSB)
*/
void store_half(unsigned char* data_memory, unsigned int address, unsigned short value) {
	if(good_address(address, sizeof(int))) {
		int i;
		for(i = 0; i < sizeof(short); i++)
			data_memory[address+i] = (value >> (sizeof(short)-1-i)*8) & 0xff;
	}
}

/*
	Stores the given byte at the address
*/
void store_byte(unsigned char* data_memory, unsigned int address, unsigned char value) {
	if(good_address(address, sizeof(int))) {
		data_memory[address] = value;
	}
}