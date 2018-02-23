#include "instruction_types.h"
#include "instruction_opcodes.h"

typedef struct r_inst_data {
	unsigned int 	opcode1: 	6;
	unsigned int 	s: 			5;
	unsigned int 	t: 			5;
	unsigned int 	d: 			5;
	unsigned int 	shift:		5;
	unsigned int 	opcode2: 	6;
} R_Data;

typedef struct i_inst_data {
	unsigned int 	opcode: 	6;
	unsigned int 	s: 			5;
	unsigned int 	t: 			5;
	unsigned int 	im:			16;
} I_Data;

typedef struct j_inst_data {
	unsigned int 	opcode: 	6;
	unsigned int 	address: 	26;
} J_Data;

int decipher_instruction(unsigned int inst, P_Regs* tmp_interstage_regs, ALU_Data* alu_data);