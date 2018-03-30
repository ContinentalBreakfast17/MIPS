#define bits_1_to_6   unsigned int(inst & 0xfc000000) >> 26;
#define bits_7_to_11  unsigned int(inst & 0x03e00000) >> 21;
#define bits_12_to_16 unsigned int(inst & 0x001f0000) >> 16;
#define bits_17_to_21 unsigned int(inst & 0x0000f800) >> 11;
#define bits_22_to_26 unsigned int(inst & 0x000007c0) >> 6;
#define bits_27_to_32 unsigned int(inst & 0x0000003f);

void i_add(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_ADD;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 1;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_addu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_ADD;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 0;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_and(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_AND;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_clo(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_CLO;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_clz(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_CLZ;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_div(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_DIV;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 1;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_divu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_DIV;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 0;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_mult(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MULT;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 1;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_multu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MULT;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 0;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_mul(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MUL;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 0;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_madd(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MADD;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 1;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_maddu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MADD;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 0;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_msub(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MSUB;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 1;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_msubu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MSUB;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 0;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_nor(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_NOR;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_sll(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SLL;
	alu_data->rs = bits_12_to_16;
	alu_data->sh = bits_22_to_26;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_SH_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_sllv(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SLL;
	alu_data->rs = bits_12_to_16;
	alu_data->rt = bits_7_to_11;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_sra(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SRA;
	alu_data->rs = bits_12_to_16;
	alu_data->sh = bits_22_to_26;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_SH_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_srav(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SRA;
	alu_data->rs = bits_12_to_16;
	alu_data->rt = bits_7_to_11;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_srl(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SRL;
	alu_data->rs = bits_12_to_16;
	alu_data->sh = bits_22_to_26;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_SH_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_srlv(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SRL;
	alu_data->rs = bits_12_to_16;
	alu_data->rt = bits_7_to_11;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_sub(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SUB;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 1;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_subu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SUBU;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->overflow = 0;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_xor(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_XOR;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_slt(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SLT;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_sltu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_SLTU;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_jalr(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_JALR;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_17_to_21;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_jr(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_JR;
	alu_data->rs = bits_7_to_11;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_teq(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_tne(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_tge(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_tgeu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_tlt(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_tltu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_mfhi(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MFHI;
	alu_data->rd = bits_17_to_21;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_mflo(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MFLO;
	alu_data->rd = bits_17_to_21;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_mthi(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MTHI;
	alu_data->rs = bits_7_to_11;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_mtlo(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MTLO;
	alu_data->rs = bits_7_to_11;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_mfc0(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MOVC;
	alu_data->rs = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_mtc0(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MOVC;
	alu_data->rs = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_movn(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MOVN;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_movz(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_MOVZ;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->rd = bits_17_to_21;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_movf(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	unsigned int cc = unsigned int(inst & 0x001c0000);
	alu_data->opcode = ALU_MOVF;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_17_to_21;
	alu_data->cc = cc;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_movt(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	unsigned int cc = unsigned int(inst & 0x001c0000);
	alu_data->opcode = ALU_MOVT;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_17_to_21;
	alu_data->cc = cc;
	alu_data->src = ALU_REG_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}