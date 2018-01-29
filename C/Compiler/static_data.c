/*
	Globals containing data and global pointer
*/
unsigned char* static_data = NULL;
unsigned int GP = 0;

void init_static_memory() {
	static_data = (unsigned char*)malloc(MEM_SIZE);
	GP = INIT_GP;
}

void store_static_word(unsigned int n) {
	while(GP % sizeof(unsigned int) != 0) GP += 1;
	store_word(static_data, GP += sizeof(unsigned int), n);
}

void store_static_half(unsigned short n) {
	while(GP % sizeof(unsigned short) != 0) GP += 1;
	store_half(static_data, GP += sizeof(unsigned short), n);
}

void store_static_byte(unsigned char n) {
	store_byte(static_data, GP += sizeof(unsigned char), n);
}

void store_static_space(unsigned int n) {
	GP += n;
}

void store_static_string(char* s, unsigned int sz) {
	int i;
	for(i = 0; i < sz; i++) {
		store_byte(static_data, GP += sizeof(unsigned char), s[i]);
	}
}

void output_static_data(FILE* f) {
	fprintf(f, "%u\n\n", GP);
	unsigned int i;
	for(i = INIT_GP; i < GP; i++) {
		fprintf(f, "0x%x\n", s[i]);
	}
}