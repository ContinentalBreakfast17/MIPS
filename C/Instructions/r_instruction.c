// TODO: branch
// u -> overflow = 0

// add, addu, and, nor, sllv, srav, srlv, sub, subu, xor, slt, sltu, movn, movz, mul
void r_type_1(unsigned int code, Inst_Bits inst, Inst* data, unsigned int overflow) {
	data->opcode = code;
	data->op_1 = new_operand(OP_I_REG, inst.r->rs, SZ_WORD);
	data->op_2 = new_operand(OP_I_REG, inst.r->rt, SZ_WORD);
	data->dest = new_dest(OP_I_REG, inst.r->rd, SZ_WORD, MEM_ALIGN_FORCE);
	data->overflow = overflow;
}

// clo, clz, jalr, mfc0, mtc0
void r_type_2(unsigned int code, Inst_Bits inst, Inst* data, int branch) {
	data->opcode = code;
	data->op_1 = new_operand(OP_I_REG, inst.r->rs, SZ_WORD);
	data->dest = new_dest(OP_I_REG, inst.r->rd, SZ_WORD, MEM_ALIGN_FORCE);
	data->branch = branch;
}

// sll, sra, srl
void r_type_3(unsigned int code, Inst_Bits inst, Inst* data) {
	data->opcode = code;
	data->op_1 = new_operand(OP_I_REG, inst.r->rs, SZ_WORD);
	data->op_2 = new_operand(OP_IM, inst.r->shift, SZ_WORD);
	data->dest = new_dest(OP_I_REG, inst.r->rd, SZ_WORD, MEM_ALIGN_FORCE);
	data->overflow = overflow;
}

// jr
void r_type_4(unsigned int code, Inst_Bits inst, Inst* data) {
	data->opcode = code;
	data->op_1 = new_operand(OP_I_REG, inst.r->rs, SZ_WORD);
	data->branch = 1;
}

// teq, tne, tge, tgeu, tlt, tltu
void r_type_5(unsigned int code, Inst_Bits inst, Inst* data, unsigned int overflow) {
	data->opcode = code;
	data->op_1 = new_operand(OP_I_REG, inst.r->rs, SZ_WORD);
	data->op_2 = new_operand(OP_I_REG, inst.r->rt, SZ_WORD);
	data->overflow = overflow;
}

// mfhi, mflo
void r_type_6(unsigned int code, Inst_Bits inst, Inst* data, unsigned int reg) {
	data->opcode = code;
	data->op_1 = new_operand(OP_I_REG, reg, SZ_WORD);
	data->dest = new_dest(OP_I_REG, inst.r->rd, SZ_WORD, MEM_ALIGN_FORCE);
}

// mthi, mtlo
void r_type_6(unsigned int code, Inst_Bits inst, Inst* data, unsigned int reg) {
	data->opcode = code;
	data->op_1 = new_operand(OP_I_REG, inst.r->rs, SZ_WORD);
	data->dest = new_dest(OP_I_REG, reg, SZ_WORD, MEM_ALIGN_FORCE);
}

// movf, movt
void r_type_7(unsigned int code, Inst_Bits inst, Inst* data) {
	data->opcode = code;
	data->op_1 = new_operand(OP_I_REG, inst.r->rs, SZ_WORD);
	data->op_2 = new_operand(OP_C_FLAG, unsigned int(inst.b & 0x001c0000), SZ_WORD);
	data->dest = new_dest(OP_I_REG, inst.r->rd, SZ_WORD, MEM_ALIGN_FORCE);
}

// div, divu, mult, multu
void r_type_8(unsigned int code, Inst_Bits inst, Inst* data, unsigned int overflow) {
	data->opcode = code;
	data->op_1 = new_operand(OP_I_REG, inst.r->rs, SZ_WORD);
	data->op_2 = new_operand(OP_I_REG, inst.r->rt, SZ_WORD);
	data->dest = new_dest(OP_I_REG, R_HI, SZ_DOUBLE, MEM_ALIGN_FORCE);
	data->overflow = overflow;
}

// madd, maddu, msub, msubu
void r_type_8(unsigned int code, Inst_Bits inst, Inst* data, unsigned int overflow) {
	data->opcode = code;
	data->op_1 = new_operand(OP_I_REG, inst.r->rs, SZ_WORD);
	data->op_2 = new_operand(OP_I_REG, inst.r->rt, SZ_WORD);
	data->op_2 = new_operand(OP_I_REG, R_HI, SZ_DOUBLE);
	data->dest = new_dest(OP_I_REG, R_HI, SZ_DOUBLE, MEM_ALIGN_FORCE);
	data->overflow = overflow;
}