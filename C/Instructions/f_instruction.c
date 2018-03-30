#define bits_12_to_16 unsigned int(inst & 0x001f0000) >> 16;
#define bits_17_to_21 unsigned int(inst & 0x0000f800) >> 11;
#define bits_22_to_26 unsigned int(inst & 0x000007c0) >> 6;

void i_f_abs(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_ABS;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_add(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_ADD;
	alu_data->rs = bits_17_to_21;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_ceil_w(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_CEIL_W;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_c_eq(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	unsigned int cc = unsigned int(inst & 0x00000700) >> 8;
	alu_data->opcode = ALU_C_EQ;
	alu_data->rs = bits_17_to_21;
	alu_data->rt = bits_12_to_16;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;
	alu_data->cc = cc;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
}

void i_f_c_le(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	unsigned int cc = unsigned int(inst & 0x00000700) >> 8;
	alu_data->opcode = ALU_C_LE;
	alu_data->rs = bits_17_to_21;
	alu_data->rt = bits_12_to_16;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;
	alu_data->cc = cc;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
}

void i_f_c_lt(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	unsigned int cc = unsigned int(inst & 0x00000700) >> 8;
	alu_data->opcode = ALU_C_LT;
	alu_data->rs = bits_17_to_21;
	alu_data->rt = bits_12_to_16;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;
	alu_data->cc = cc;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
}

void i_f_cvt_d(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_CVT_D;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_cvt_s(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_CVT_S;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_cvt_w(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_CVT_W;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_div(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_DIV;
	alu_data->rs = bits_17_to_21;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_floor_w(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_FLOOR_W;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_mov(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_MOV;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_movf(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	unsigned int cc = unsigned int(inst & 0x001c0000) >> 16;
	alu_data->opcode = ALU_MOVF;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;
	alu_data->cc = cc;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_movt(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	unsigned int cc = unsigned int(inst & 0x001c0000) >> 16;
	alu_data->opcode = ALU_MOVT;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;
	alu_data->cc = cc;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_movn(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_MOVN;
	alu_data->rs = bits_17_to_21;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_movn(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_MOVN;
	alu_data->rs = bits_17_to_21;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_movz(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_MOVZ;
	alu_data->rs = bits_17_to_21;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_mul(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_MUL;
	alu_data->rs = bits_17_to_21;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_neg(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_NEG;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_round_w(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_ROUND_W;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_sqrt(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_SQRT;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_sub(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_SUB;
	alu_data->rs = bits_17_to_21;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}

void i_f_trunc_w(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int sz) {
	alu_data->opcode = ALU_TRUNC_W;
	alu_data->rs = bits_17_to_21;
	alu_data->rd = bits_22_to_26;
	alu_data->fp_op = 1;
	alu_data->fp_sz = sz;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->rd = alu_data->rd;
}