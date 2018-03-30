#define bits_1_to_6   unsigned int(inst & 0xfc000000) >> 26;
#define bits_7_to_11  unsigned int(inst & 0x03e00000) >> 21;
#define bits_12_to_16 unsigned int(inst & 0x001f0000) >> 16;
#define bits_17_to_32 unsigned int(inst & 0x0000ffff);

void i_addi(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_ADD;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->overflow = 1;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_addiu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_ADD;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
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
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_ori(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_OR;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_xori(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_XOR;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_lui(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_LUI;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->rd = alu_data->rd;
}

void i_bclf(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	unsigned int cc = unsigned int(inst & 0x001c0000);
	alu_data->opcode = ALU_B;
	alu_data->im = bits_17_to_32;
	alu_data->cc = cc;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_bclt(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	unsigned int cc = unsigned int(inst & 0x001c0000);
	alu_data->opcode = ALU_B;
	alu_data->im = bits_17_to_32;
	alu_data->cc = cc;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_beq(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_B;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_bgez(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_B;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_bgezal(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_B;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_bgtz(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_B;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_blez(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_B;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_bltzal(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_B;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_bltz(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_B;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_bne(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_B;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_teqi(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_tgei(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_tgeiu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_tlti(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_tltiu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_T;
	alu_data->rs = bits_7_to_11;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 0;
	p_id->reg_wr = 0;
}

void i_lb(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_L;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 1;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(char);
	p_id->rd = alu_data->rd;
}

void i_lbu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_L;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 2;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(char);
	p_id->rd = alu_data->rd;
}

void i_lh(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_L;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 1;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(short);
	p_id->rd = alu_data->rd;
}

void i_lhu(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_L;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 2;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(short);
	p_id->rd = alu_data->rd;
}

void i_lw(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_L;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 1;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(int);
	p_id->rd = alu_data->rd;
}

void i_lwc1(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_L;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 1;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 1;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(int);
	p_id->rd = alu_data->rd;
}

void i_lwl(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_L;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 1;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_LEFT;
	p_id->mem_op_sz = sizeof(int);
	p_id->rd = alu_data->rd;
}

void i_lwr(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_L;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 1;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_RIGHT;
	p_id->mem_op_sz = sizeof(int);
	p_id->rd = alu_data->rd;
}

void i_ll(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_L;
	alu_data->rs = bits_7_to_11;
	alu_data->rd = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 1;
	p_id->mem_wr = 0;
	p_id->reg_wr = 1;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(int);
	p_id->rd = alu_data->rd;
}

void i_sb(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_S;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 1;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(char);
	p_id->rd = alu_data->rd;
}

void i_sh(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_S;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 1;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(short);
	p_id->rd = alu_data->rd;
}

void i_sw(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_S;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 1;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(int);
	p_id->rd = alu_data->rd;
}

void i_swc1(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_S;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 1;

	p_id->mem_rd = 0;
	p_id->mem_wr = 1;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(float);
	p_id->rd = alu_data->rd;
}

void i_sdc1(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_S;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 1;

	p_id->mem_rd = 0;
	p_id->mem_wr = 1;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(double);
	p_id->rd = alu_data->rd;
}

void i_swr(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_S;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 1;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_RIGHT;
	p_id->mem_op_sz = sizeof(int);
	p_id->rd = alu_data->rd;
}

void i_swl(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_S;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 1;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_LEFT;
	p_id->mem_op_sz = sizeof(int);
	p_id->rd = alu_data->rd;
}

void i_sc(unsigned int inst, P_ID* p_id, ALU_Data* alu_data, int* branch) {
	alu_data->opcode = ALU_S;
	alu_data->rs = bits_7_to_11;
	alu_data->rt = bits_12_to_16;
	alu_data->im = bits_17_to_32;
	alu_data->src = ALU_IM_SRC;
	alu_data->fp_op = 0;

	p_id->mem_rd = 0;
	p_id->mem_wr = 1;
	p_id->reg_wr = 0;
	p_id->fp_wr = 0;
	p_id->mem_align = MEM_ALIGN_FORCE;
	p_id->mem_op_sz = sizeof(int);
	p_id->rd = alu_data->rd;
}