void i_eret(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_ERET;
	alu_data->fp_op = 0;
	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_syscall(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SYSCALL;
	alu_data->fp_op = 0;
	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_break(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_BREAK;
	alu_data->fp_op = 0;
	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_nop(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_NOP;
	alu_data->fp_op = 0;
	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}