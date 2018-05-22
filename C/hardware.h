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
	Regs* 			registers;
	unsigned char* 	memory;
	Register_File* 	reg_file;
	Reorder_Buffer* rob;
	Stations* 		res_stations; 		
} Hardware;