#define MEM_SIZE 0x80000000
#define INIT_GP  0x10000000

unsigned char* 	init_memory();
int 			load_word(unsigned char* data_memory, unsigned int address);
short 			load_half(unsigned char* data_memory, unsigned int address);
char 			load_byte(unsigned char* data_memory, unsigned int address);
void 			store_word(unsigned char* data_memory, unsigned int address, unsigned int value);
void 			store_half(unsigned char* data_memory, unsigned int address, unsigned short value);
void 			store_byte(unsigned char* data_memory, unsigned int address, unsigned char value);