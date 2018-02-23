#define MEM_SIZE 0x80000000
#define INIT_GP  0x10000000

unsigned char* 	init_memory();
int 			load_word(unsigned char* data_memory, unsigned int address, void* retval);
int 			load_half(unsigned char* data_memory, unsigned int address, void* retval);
int 			load_byte(unsigned char* data_memory, unsigned int address, void* retval);
int 			store_word(unsigned char* data_memory, unsigned int address, void* value);
int 			store_half(unsigned char* data_memory, unsigned int address, void* value);
int 			store_byte(unsigned char* data_memory, unsigned int address, void* value);