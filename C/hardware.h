/*
	Includes
*/
#include "./util.h"
#include "Registers/registers.h"
#include "Registers/f_registers.h"
#include "Data_Memory/memory.h"
#include "Instruction_Memory/instruction.h"

typedef struct base_hardware {
	PC* 			program_counter;
	int* 			registers;
	float*			f_registers;
	unsigned char* 	memory;
	char* 			condition_flags;
} Hardware;