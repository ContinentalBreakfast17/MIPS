#define MEM_SIZE 					0x80000000
#define INIT_GP  					0x10000000
#define MEM_ALIGN_FORCE 			0
#define MEM_ALIGN_RIGHT 			1
#define MEM_ALIGN_LEFT 				2
#define STORE 						0
#define LOAD 						1

unsigned char* 	init_memory();
int 			store_data(unsigned char* memory, unsigned int address, unsigned long long value, unsigned int size, unsigned int alignment);
int 			load_data(unsigned char* memory, unsigned int address, unsigned long long* value, unsigned int size, unsigned int alignment, unsigned int signage);