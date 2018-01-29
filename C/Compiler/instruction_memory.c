/*
	Instruction memory struct maintains a resizable array of instructions
*/
typedef struct instruction_holder {
	Instruction*	instructions;
	int 			capacity;
	int 			count;
} Instruction_Memory;

/*
	Global containing instruction memory
*/
Instruction_Memory* instruction_memory = NULL; 

/*
	Initialize instruction memory to be able to hold 64 instructions
*/
void init_instruction_memory() {
	instruction_memory = (Instruction_Memory*)malloc(sizeof(Instruction_Memory));
	check_alloc((void*)instruction_memory);
	instruction_memory->instructions = (Instruction*)malloc(sizeof(Instruction)*I_MEM_SZ);
	check_alloc((void*)instruction_memory->instructions);
	instruction_memory->capacity = I_MEM_SZ;
	instruction_memory->count = 0;
}

/*
	Returns the count field of the instruction memory
*/
int get_instruction_count() {
	return instruction_memory->count;
}

/*
	Frees all the instructions and then frees instruction memory
*/
void free_instruction_memory() {
	int i;
	for(i = 0; i < instruction_memory->count; i++) {
		instruction = instruction_memory->instructions[i];
		free(instruction->data);
		free(instruction);
	}
	free(instruction_memory);
}

/*
	Adds the instruction to instruction memory
*/
void add_instruction(Instruction* instruction) {
	if(instruction_memory->count == instruction_memory->capacity) {
		instruction_memory->capacity *= 2;
		instruction_memory->instructions = (Instruction*)realloc(instruction_memory->instructions, instruction_memory->capacity*sizeof(Instruction));
		check_alloc((void*)instruction_memory->instructions);
	}
	instruction_memory->instructions[count++] = instruction;
}

/*
	Creates a new instruction
	Switches on the operation to determine the helper function to call to new the instruction
	Non-native mips instructions such as BGTZ are mapped to multiple instructions
*/
void new_instruction(int operation, int arg1, int arg2, int arg3, char* target) {
	
}

/*
	Sets the address field of the branch instruction data according to the target index
	Parameter i provides the index of the current instruction
*/
void set_branch_target(Instruction* instruction, int index) {
	int target_index = get_target(instruction->target);
	if(index < 0) {
		printf("Error: Jump target '%s' used but never defined\n", instruction->target);
		exit(1);
	}
	int target_address = index*4 + INIT_PC;
	int inst_address = index*4 + INIT_PC;
	I_Data* data = (I_Data*)instruction->data;
	data->address = inst_address+4 - address;
}

/*
	Sets the address field of the jump instruction data according to the target index
*/
void set_jump_target(Instruction* instruction) {
	int index = get_target(instruction->target);
	if(index < 0) {
		printf("Error: Jump target '%s' used but never defined\n", instruction->target);
		exit(1);
	}
	int address = index*4 + INIT_PC;
	J_Data* data = (J_Data*)instruction->data;
	data->address = (address & 0x0fffffff) >> 2;
}

/*
	Searches instruction memory and replaces the targets with the proper offset
*/
void replace_targets() {
	int i;
	for(i = 0; i < instruction_memory->count; i++) {
		instruction = instruction_memory->instructions[i];
		if(instruction->type == I_TYPE_B)
			set_branch_target(instruction, i);
		else if(instruction->type == I_TYPE_J)
			set_jump_target(instruction);
	}
}