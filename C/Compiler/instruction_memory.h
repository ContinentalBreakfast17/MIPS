#define I_TYPE_R 0
#define I_TYPE_B 1
#define I_TYPE_J 2
#define I_MEM_SZ 64

typedef struct abstract_instruction {
	void* 	data;
	char* 	target;
	int 	type;
} Instruction;

void 	init_instruction_memory();
void 	replace_targets();
int 	get_instruction_count();
void 	free_instruction_memory();
void 	add_instruction(Instruction* instruction);