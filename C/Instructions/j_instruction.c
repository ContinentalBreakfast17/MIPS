void i_j(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	unsigned int target = unsigned int(inst & 0x03ffffff);
	
	alu_data->opcode = ALU_J;
	alu_data->jump_target = target;
	alu_data->fp_op = 0;
	
	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_jal(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	unsigned int target = unsigned int(inst & 0x03ffffff);

	alu_data->opcode = ALU_JAL;
	alu_data->jump_target = target;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}