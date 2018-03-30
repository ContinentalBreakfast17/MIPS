#define STAGE_IF 	0
#define STAGE_ID 	1
#define STAGE_EXE 	2
#define STAGE_MEM	3
#define STAGE_WB	4

typedef struct instruction_fetch {
	unsigned int	inst;		// the instruction
} P_IF;

typedef struct instruction_decode {
	unsigned int 	rd;			// destination register
	unsigned int 	mem_rd;		// whether memory will be read
	unsigned int 	mem_wr;		// whether memory will be written
	unsigned int 	mem_op_sz;	// size of memory to be read/written, e.g. byte, half, word...
	unsigned int 	mem_align; 	// whether memory should align by mem_op_sz, or if it is stored/loaded right or left
	unsigned int 	reg_wr;		// whether register will be written
	unsigned int 	fp_wr; 		// whether operation writes back to floating point register
} P_ID;

typedef struct instruction_execute {
	unsigned int 	alu_result;	// result of alu computation
	unsigned int 	data_2;		// value of rt
	unsigned int 	mem_op_sz;
	unsigned int 	mem_align;
	unsigned int 	rd;
	unsigned int 	mem_rd;
	unsigned int 	mem_wr;
	unsigned int 	reg_wr;
	unsigned int 	fp_wr;
} P_EXE;

typedef struct instruction_memory_access {
	unsigned int 	alu_result;
	unsigned int 	mem_data;	// memory read from load operation
	unsigned int 	rd;
	unsigned int 	mem_rd;
	unsigned int 	reg_wr;
	unsigned int 	fp_wr;
} P_MEM;

typedef struct interstage_registers {
	P_IF* 			p_if;
	P_ID* 			p_id;
	P_EXE* 			p_exe;
	P_MEM* 			p_mem;
} P_Regs;

P_Regs* init_interstage_regs();
void copy_interstage_regs(P_Regs* dest, P_Regs* src, int stage);
void free_interstage_registers(P_Regs* interstage_regs);
// forwarding