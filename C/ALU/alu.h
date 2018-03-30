#define TERMINATE 				-1
#define TERMINATE_CODE 			-2
#define ALU_INTEGER_OVERFLOW 	10

#define ALU_REG_SRC 			0
#define ALU_IM_SRC 				1
#define ALU_SH_SRC				2

typedef union alu_arg_data {
	int 			i;
	float 			f;
} ALU_Arg;

typedef struct alu_inst_data {
	ALU_Arg			retval;
	unsigned int 	pc;
	unsigned int	opcode;
	unsigned int	jump_target: 	26;
	short 			im;
	unsigned int 	reg_1: 			5;
	unsigned int 	reg_2: 			5;
	unsigned int 	reg_dest:		5;
	char 			shamt:			5;
	char 			cc: 			3;
	char 			src: 			2;
	char 			overflow: 		1;
	char 			fp_op:			1;
	char 			fp_sz:			1;
} ALU_Data;

int compute(int control, int src, int arg1, int arg2, short im, unsigned int pc, int jump_target, (void*)retval);
int compute_float(int control, int src, float arg1, float arg2, short im, unsigned int pc, (void*)retval);