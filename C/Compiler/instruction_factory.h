void 			new_instruction(unsigned int inst, unsigned int rs, unsigned int rt, unsigned int rd, unsigned int im, unsigned int sh, char* tg);
Instruction* 	new_r_instruction(unsigned int opcode1, unsigned int s, unsigned int t, unsigned int d, unsigned int shift, unsigned int opcode2, char* target);
Instruction* 	new_i_instruction(unsigned int opcode, unsigned int s, unsigned int t, unsigned int im, char* target);
Instruction* 	new_j_instruction(unsigned int opcode, char* target);