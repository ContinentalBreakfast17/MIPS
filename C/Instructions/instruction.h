#define OP_I_REG 	0
#define OP_F_REG 	1
#define OP_C_FLAG 	2
#define OP_IM 		3

typedef struct r_inst_data {
	unsigned int 	opcode2: 	6;
	unsigned int 	shift:		5;
	unsigned int 	d: 			5;
	unsigned int 	t: 			5;
	unsigned int 	s: 			5;
	unsigned int 	opcode1: 	6;
} R_Data;

typedef struct i_inst_data {
	unsigned int 	im:			16;
	unsigned int 	t: 			5;
	unsigned int 	s: 			5;
	unsigned int 	opcode: 	6;
} I_Data;

typedef struct j_inst_data {
	unsigned int 	address: 	26;
	unsigned int 	opcode: 	6;
} J_Data;

typedef union {
	unsigned int 	b;
	R_Data 			r;
	I_Data 			i;
	J_Data 			j;
} Inst_Bits;

typedef struct instruction_dest {
	unsigned int 	type;
	unsigned int 	value;
	unsigned int 	size;
	unsigned int 	alignment;
} Inst_Dest;

typedef struct instruction_operand {
	unsigned int 	type;
	unsigned int 	value;
	unsigned int 	size;
} Operand;

typedef struct instruction_data {
	Operand* 		op_1;
	Operand* 		op_2;
	Operand* 		op_3; // only useful for MADD / MSUB :(
	Inst_Dest* 		dest;
	unsigned int 	opcode;
	unsigned int 	pc;
	unsigned int 	overflow: 	1;
	unsigned int 	fp: 		1;
	unsigned int 	branch: 	1;
} Inst_Data;

int decipher_instruction(unsigned int inst, P_Regs* tmp_interstage_regs, ALU_Data* alu_data);