#define TERMINATE 				-1
#define TERMINATE_CODE 			-2
#define ALU_INTEGER_OVERFLOW 	10

typedef union alu_arg_data {
	int 			i;
	float 			f;
} ALU_Arg;

typedef struct alu_inst_data {
	ALU_Arg			retval;
	ALU_Arg 		arg1;
	ALU_Arg 		arg2;
	unsigned int 	pc;
	unsigned int	control;
	unsigned int	jump_target: 	26;
	short 			im;
	unsigned int 	rs: 			5;
	unsigned int 	rt: 			5;
	unsigned int 	rd: 			5;
	char 			shamt:			5;
	char 			cc: 			3;
	char 			src: 			1;
	char 			overflow: 		1;
} ALU_Data;

int compute(int control, int src, int arg1, int arg2, short im, unsigned int pc, int jump_target, (void*)retval);
int compute_float(int control, int src, float arg1, float arg2, short im, unsigned int pc, (void*)retval);