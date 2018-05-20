#define MEM_SIZE 0x80000000
#define INIT_GP  0x10000000
#define MEM_ALIGN_FORCE 			0
#define MEM_ALIGN_RIGHT 			1
#define MEM_ALIGH_LEFT 				2
#define STORE 						0
#define LOAD 						1

unsigned char* 	init_memory();
int 			load_word(unsigned char* data_memory, unsigned int address, void* retval);
int 			load_half(unsigned char* data_memory, unsigned int address, void* retval);
int 			load_byte(unsigned char* data_memory, unsigned int address, void* retval);

int store_data(unsigned char* memory, unsigned int address, unsigned long long value, unsigned int size, unsigned int alignment);