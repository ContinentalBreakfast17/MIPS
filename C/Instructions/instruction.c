/*	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;
	unsigned int bits_7_to_11 = unsigned int(inst & 0x03e00000) >> 21;
	unsigned int bits_12_to_16 = unsigned int(inst & 0x001f0000) >> 16;
	unsigned int bits_17_to_21 = unsigned int(inst & 0x0000f800) >> 11;
	unsigned int bits_22_to_26 = unsigned int(inst & 0x000007c0) >> 6;
	unsigned int bits_27_to_32 = unsigned int(inst & 0x0000003f);*/

int is_e_instruction(unsigned int inst) {
	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;
	unsigned int bits_27_to_32 = unsigned int(inst & 0x0000003f);
	return ((bits_1_to_6 == 0 && bits_27_to_32 == 12) || inst == 0 || inst == 12 || inst == 1107296280);
}

int is_j_instruction(unsigned int inst) {
	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;
	return (bits_1_to_6 == 2 || bits_1_to_6 == 3);
}

int is_f_instruction(unsigned int inst) {
	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;
	return (bits_1_to_6 == 17);
}

int is_r_instruction(unsigned int inst) {
	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;
	return (bits_1_to_6 == 0 || bits_1_to_6 == 28 || bits_1_to_6 == 16);
}

int is_i_instruction(unsigned int inst) {
	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;
	switch(bits_1_to_6) {
		case 8, 9, 12, 13, 14, 15, 10, 11, 1, 4, 7, 6, 5, 32, 36, 33, 37, 35, 49, 34, 38, 48, 40, 41, 43, 59, 42, 46, 56, 18, 19:
			return 1;
		default:
			return 0;
	}
}


/*
	Extracts the information from a given instruction
	Returns relevant information to ID stage of tmp_interstage_regs and alu_data
	Also resolves branch and stores the branch info
*/
int parse_instruction(unsigned int inst, P_Regs* tmp_interstage_regs, ALU_Data* alu_data, int* branch) {
	/*
		The order is mostly unimportant, but exception instruction detection must come first
	*/
	if(is_e_instruction(inst)) return parse_e_instruction(inst, tmp_interstage_regs, alu_data, branch);
	else if(is_j_instruction(inst)) return parse_j_instruction(inst, tmp_interstage_regs, alu_data, branch);
	else if(is_r_instruction(inst)) return parse_r_instruction(inst, tmp_interstage_regs, alu_data, branch);
	else if(is_f_instruction(inst)) return parse_f_instruction(inst, tmp_interstage_regs, alu_data, branch);
	else if(is_i_instruction(inst)) return parse_i_instruction(inst, tmp_interstage_regs, alu_data, branch);
	else return BAD_INSTRUCTION;
}

int parse_e_instruction(unsigned int inst, P_Regs* tmp_interstage_regs, ALU_Data* alu_data, int* branch) {
	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;
	unsigned int bits_27_to_32 = unsigned int(inst & 0x0000003f);
	
	if(bits_1_to_6 == 0 && bits_27_to_32 == 12) i_eret(inst, tmp_interstage_regs, alu_data, branch);
	else if(inst == 0) i_nop(inst, tmp_interstage_regs, alu_data, branch);
	else if(inst == 12) i_syscall(inst, tmp_interstage_regs, alu_data, branch);
	else if(inst == 1107296280) i_break(inst, tmp_interstage_regs, alu_data, branch);
	else return BAD_INSTRUCTION;
	return 0;
}

int parse_j_instruction(unsigned int inst, P_Regs* tmp_interstage_regs, ALU_Data* alu_data, int* branch) {
	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;

	if(bits_1_to_6 == I_OP_J) i_j(inst, tmp_interstage_regs, alu_data, branch);
	else if(bits_1_to_6 == I_OP_JAL) i_jal(inst, tmp_interstage_regs, alu_data, branch);
	else return BAD_INSTRUCTION;
	return 0;
}

int parse_r_instruction(unsigned int inst, P_Regs* tmp_interstage_regs, ALU_Data* alu_data, int* branch) {
	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;
	unsigned int bits_7_to_11 = unsigned int(inst & 0x03e00000) >> 21;

	switch(bits_1_to_6) {
		case 0:
			switch(bits_27_to_32) {
				case I_OP_ADD: i_add(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_ADDU: i_addu(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_AND: i_and(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_DIV: i_div(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_DIVU: i_divu(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MULT: i_mult(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MULTU: i_multu(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MUL: i_mul(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_NOR: i_nor(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_OR: i_or(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_SLL: i_sll(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_SLLV: i_sllv(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_SRA: i_sra(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_SRAV: i_srav(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_SRL: i_srl(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_SRLV: i_srlv(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_SUB: i_sub(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_SUBU: i_subu(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_XOR: i_xor(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_SLT: i_slt(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_SLTU: i_sltu(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_JALR: i_jalr(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_JR: i_jr(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TEQ: i_teq(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TNE: i_tne(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TGE: i_tge(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TGEU: i_tgeu(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TLT: i_tlt(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TLTU: i_tltu(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MFHI: i_mfhi(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MFLO: i_mflo(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MTHI: i_mthi(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MTLO: i_mtlo(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MOVN: i_movn(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MOVZ: i_movz(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MOVF: i_movf(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MOVT: i_movt(inst, tmp_interstage_regs, alu_data, branch); break;
				default: return BAD_INSTRUCTION;
			}
			break;
		case 1:
			unsigned int cc = unsigned int(inst & 0x00030000);
			if(cc) i_movt(inst, tmp_interstage_regs, alu_data, branch);
			else i_movf(inst, tmp_interstage_regs, alu_data, branch);
			break;;
		case 0x1c:
			switch(bits_27_to_32) {
				case I_OP_CLO: i_clo(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_CLZ: i_clz(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MADD: i_madd(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MADDU: i_maddu(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MSUB: i_msub(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MSUBU: i_msubu(inst, tmp_interstage_regs, alu_data, branch); break;
				default: return BAD_INSTRUCTION;
			}
			break;
		case 0x10:
			switch(bits_7_to_11) {
				case I_OP_MFC0: i_mfc0(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_MTC0: i_mtc0(inst, tmp_interstage_regs, alu_data, branch); break;
				default: return BAD_INSTRUCTION;
			}
			break;
		default: return BAD_INSTRUCTION;
	}
	return 0;
}

int parse_i_instruction(unsigned int inst, P_Regs* tmp_interstage_regs, ALU_Data* alu_data, int* branch) {
	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;
	unsigned int bits_12_to_16 = unsigned int(inst & 0x001f0000) >> 16;

	switch(bits_1_to_6) {
		case 1:
			switch(bits_12_to_16) {
				case I_OP_BGEZ: i_bgez(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_BGEZAL: i_bgezal(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_BLTZAL: i_bltzal(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_BLTZ: i_bltz(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TEQI: i_teqi(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TNEI: i_tnei(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TGEI: i_tgei(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TGEIU: i_tgeiu(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TLTI: i_tlti(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_TLTIU: i_tltiu(inst, tmp_interstage_regs, alu_data, branch); break;
				default: return BAD_INSTRUCTION;
			}
			break;
		case I_OP_ADDI: i_addi(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_ADDIU: i_addiu(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_ANDI: i_andi(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_ORI: i_ori(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_XORI: i_xori(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_LUI: i_lui(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_SLTI: i_slti(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_SLTIU: i_sltiu(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_OP_BCLF: i_bclf(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_OP_BCLT: i_bclt(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_BEQ: i_beq(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_BGTZ: i_bgtz(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_BLEZ: i_blez(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_BNE: i_bne(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_LB: i_lb(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_LBU: i_lbu(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_LH: i_lh(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_LHU: i_lhu(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_LW: i_lw(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_LWC1: i_lwc1(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_LWL: i_lwl(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_LWR: i_lwr(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_LL: i_ll(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_SB: i_sb(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_SH: i_sh(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_SW: i_sw(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_SWC1: i_swc1(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_SDC1: i_sdc1(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_SWL: i_swl(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_SWR: i_swr(inst, tmp_interstage_regs, alu_data, branch); break;
		case I_OP_SC: i_sc(inst, tmp_interstage_regs, alu_data, branch); break;
		default: return BAD_INSTRUCTION;
	}
	return 0;
}

int parse_f_instruction(unsigned int inst, P_Regs* tmp_interstage_regs, ALU_Data* alu_data, int* branch) {
	unsigned int bits_7_to_11 = unsigned int(inst & 0x03e00000) >> 21;
	unsigned int bits_27_to_32 = unsigned int(inst & 0x0000003f);
	unsigned int fc = unsigned int(inst & 0x00000030);

	// Floating point comparison instruction
	if(fc == 0x30) {
		unsigned int fc_code = unsigned int(inst & 0x00000000f);
		switch(bits_7_to_11) {
			case 0x10:
				switch(fc_code) {
					case I_OP_F_CEQ: i_ceq_s(inst, tmp_interstage_regs, alu_data, branch); break;
					case I_OP_F_CLE: i_cle_s(inst, tmp_interstage_regs, alu_data, branch); break;
					case I_OP_F_CLT: i_clt_s(inst, tmp_interstage_regs, alu_data, branch); break;
					default: return BAD_INSTRUCTION;
				}
				break;
			case 0x11:
				switch(fc_code) {
					case I_OP_F_CEQ: i_ceq_d(inst, tmp_interstage_regs, alu_data, branch); break;
					case I_OP_F_CLE: i_cle_d(inst, tmp_interstage_regs, alu_data, branch); break;
					case I_OP_F_CLT: i_clt_d(inst, tmp_interstage_regs, alu_data, branch); break;
					default: return BAD_INSTRUCTION;
				}
				break;
			default: return BAD_INSTRUCTION;
		}
		return 0;
	}

	switch(bits_7_to_11) {
		case 0:
			i_mfc1(inst, tmp_interstage_regs, alu_data, branch); break;
		case 1:
			i_mtc1(inst, tmp_interstage_regs, alu_data, branch); break;
		case 0x10:
			switch(bits_27_to_32) {
				case 0x11:
					unsigned int cc = unsigned int(inst & 0x00030000);
					if(cc) i_movt_s(inst, tmp_interstage_regs, alu_data, branch);
					else i_movf_s(inst, tmp_interstage_regs, alu_data, branch);
					break;
				case I_OP_F_ABS: i_abs_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_ADD: i_add_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_CEIL_W: i_ceil_w_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_CVT_D: i_cvt_d_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_CVT_W: i_cvt_w_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_DIV: i_div_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_FLOOR_W: i_floor_w_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MOV: i_mov_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MOVF: i_movf_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MOVT: i_movt_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MOVN: i_movn_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MOVZ: i_movz_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MUL: i_mul_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_NEG: i_neg_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_ROUND_W: i_round_w_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_SQRT: i_sqrt_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_SUB: i_sub_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_TRUNC_W: i_trunc_w_s(inst, tmp_interstage_regs, alu_data, branch); break;
				default: return BAD_INSTRUCTION;
			}
			break;
		case 0x11:
			switch(bits_27_to_32) {
				case 0x11:
					unsigned int cc = unsigned int(inst & 0x00030000);
					if(cc) i_movt_d(inst, tmp_interstage_regs, alu_data, branch);
					else i_movf_d(inst, tmp_interstage_regs, alu_data, branch);
					break;
				case I_OP_F_ABS: i_abs_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_ADD: i_add_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_CEIL_W: i_ceil_w_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_CVT_S: i_cvt_s_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_CVT_W: i_cvt_w_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_DIV: i_div_s(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_FLOOR_W: i_floor_w_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MOV: i_mov_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MOVF: i_movf_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MOVT: i_movt_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MOVN: i_movn_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MOVZ: i_movz_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_MUL: i_mul_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_NEG: i_neg_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_ROUND_W: i_round_w_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_SQRT: i_sqrt_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_SUB: i_sub_d(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_TRUNC_W: i_trunc_w_d(inst, tmp_interstage_regs, alu_data, branch); break;
				default: return BAD_INSTRUCTION;
			}
			break;
		case 0x14:
			switch(bits_27_to_32) {
				case I_OP_F_CVT_D: i_cvt_d_w(inst, tmp_interstage_regs, alu_data, branch); break;
				case I_OP_F_CVT_S: i_cvt_s_w(inst, tmp_interstage_regs, alu_data, branch); break;
			}
			break;
		default: return BAD_INSTRUCTION;
	}
	return 0;
}