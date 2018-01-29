#define INIT_PC 0x04000000

/*
	A struct containing the program counter as well as the entry point
*/
typedef struct program_counter {
	unsigned int 	counter;
	unsigned int 	entry_point;
} PC;

PC* init_pc(unsigned int entry_point);
int get_pc(PC* program_counter);
int advance_pc(PC* program_counter, int val);
int set_pc(PC* program_counter, unsigned int address);