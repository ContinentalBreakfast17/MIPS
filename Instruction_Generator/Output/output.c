case I_ABS:

	break;
case I_ADD:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x20));
	break;
case I_ADDU:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x21));
	break;
case I_ADDI:
	add_instruction(new_i_inst(0x08, rs, rt, im, NULL));
	break;
case I_ADDIU:
	add_instruction(new_i_inst(0x09, rs, rt, im, NULL));
	break;
case I_AND:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x24));
	break;
case I_ANDI:
	add_instruction(new_i_inst(0x0c, rs, rt, im, NULL));
	break;
case I_CLO:
	add_instruction(new_r_inst(0x1c, rs, 0, rd, 0, 0x21));
	break;
case I_CLZ:
	add_instruction(new_r_inst(0x1c, rs, 0, rd, 0, 0x20));
	break;
case I_DIV:
	add_instruction(new_r_inst(0x00, rs, rt, 0, 0, 0x1a));
	break;
case I_DIVU:
	add_instruction(new_r_inst(0x00, rs, rt, 0, 0, 0x1b));
	break;
case I_MULT:
	add_instruction(new_r_inst(0x00, rs, rt, 0, 0, 0x18));
	break;
case I_MULTU:
	add_instruction(new_r_inst(0x00, rs, rt, 0, 0, 0x19));
	break;
case I_MUL:
	add_instruction(new_r_inst(0x1c, rs, rt, rd, 0, 0x02));
	break;
case I_MADD:
	add_instruction(new_r_inst(0x1c, rs, rt, 0, 0, 0x00));
	break;
case I_MADDU:
	add_instruction(new_r_inst(0x1c, rs, rt, 0, 0, 0x01));
	break;
case I_MSUB:
	add_instruction(new_r_inst(0x1c, rs, rt, 0, 0, 0x04));
	break;
case I_MSUBU:
	add_instruction(new_r_inst(0x1c, rs, rt, 0, 0, 0x05));
	break;
case I_NEG:

	break;
case I_NOR:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x27));
	break;
case I_NOT:

	break;
case I_OR:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x25));
	break;
case I_ORI:
	add_instruction(new_i_inst(0x0d, rs, rt, im, NULL));
	break;
case I_SLL:
	add_instruction(new_r_inst(0x00, 0, rt, rd, sh, 0x00));
	break;
case I_SLLV:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x04));
	break;
case I_SRA:
	add_instruction(new_r_inst(0x00, 0, rt, rd, sh, 0x07));
	break;
case I_SRL:
	add_instruction(new_r_inst(0x00, 0, rt, rd, sh, 0x02));
	break;
case I_SRLV:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x06));
	break;
case I_SUB:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x22));
	break;
case I_SUBU:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x23));
	break;
case I_XOR:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x26));
	break;
case I_XORI:
	add_instruction(new_i_inst(0x0e, rs, rt, im, NULL));
	break;
case I_LUI:
	add_instruction(new_i_inst(0x0f, 0, rt, im, NULL));
	break;
case I_LI:

	break;
case I_SLT:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x2a));
	break;
case I_SLTU:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x2b));
	break;
case I_SLTI:
	add_instruction(new_i_inst(0x0a, rs, rt, im, NULL));
	break;
case I_SLTIU:
	add_instruction(new_i_inst(0x0b, rs, rt, im, NULL));
	break;
case I_SGE:

	break;
case I_SGT:

	break;
case I_B:

	break;
case I_BCLF:
	add_instruction(new_i_inst(0x11, 8, c0, 0, tg));
	break;
case I_BCLT:
	add_instruction(new_i_inst(0x11, 8, c1, 0, tg));
	break;
case I_BEQ:
	add_instruction(new_i_inst(0x04, rs, rt, 0, tg));
	break;
case I_BGEZ:
	add_instruction(new_i_inst(0x01, rs, 1, 0, tg));
	break;
case I_BGEZAL:
	add_instruction(new_i_inst(0x01, rs, 17, 0, tg));
	break;
case I_BGTZ:
	add_instruction(new_i_inst(0x07, rs, 0, 0, tg));
	break;
case I_BLEZ:
	add_instruction(new_i_inst(0x06, rs, 0, 0, tg));
	break;
case I_BLTZAL:
	add_instruction(new_i_inst(0x01, rs, 16, 0, tg));
	break;
case I_BLTZ:
	add_instruction(new_i_inst(0x01, rs, 0, 0, tg));
	break;
case I_BNE:
	add_instruction(new_i_inst(0x05, rs, rt, 0, tg));
	break;
case I_BEQZ:

	break;
case I_BGE:

	break;
case I_BGEU:

	break;
case I_BGT:

	break;
case I_BGTU:

	break;
case I_BLE:

	break;
case I_BLEU:

	break;
case I_BLT:

	break;
case I_BLTU:

	break;
case I_BNEZ:

	break;
case I_J:
	add_instruction(new_j_inst(0x02, tg));
	break;
case I_JAL:
	add_instruction(new_j_inst(0x03, tg));
	break;
case I_JALR:
	add_instruction(new_r_inst(0x00, rs, 0, rd, 0, 0x09));
	break;
case I_JR:
	add_instruction(new_r_inst(0x00, rs, 0, 0, 0, 0x08));
	break;
case I_TEQ:
	add_instruction(new_r_inst(0x00, rs, rt, 0, 0, 0x34));
	break;
case I_TEQI:
	add_instruction(new_i_inst(0x01, rs, 12, im, NULL));
	break;
case I_TNE:
	add_instruction(new_r_inst(0x00, rs, rt, 0, 0, 0x36));
	break;
case I_TNEI:
	add_instruction(new_i_inst(0x01, rs, 14, im, NULL));
	break;
case I_TGE:
	add_instruction(new_r_inst(0x00, rs, rt, 0, 0, 0x30));
	break;
case I_TGEU:
	add_instruction(new_r_inst(0x00, rs, rt, 0, 0, 0x31));
	break;
case I_TGEI:
	add_instruction(new_i_inst(0x01, rs, 8, im, NULL));
	break;
case I_TGEIU:
	add_instruction(new_i_inst(0x01, rs, 9, im, NULL));
	break;
case I_TLT:
	add_instruction(new_r_inst(0x00, rs, rt, 0, 0, 0x32));
	break;
case I_TLTU:
	add_instruction(new_r_inst(0x00, rs, rt, 0, 0, 0x33));
	break;
case I_TLTI:
	add_instruction(new_i_inst(0x01, rs, 10, im, NULL));
	break;
case I_TLTIU:
	add_instruction(new_i_inst(0x01, rs, 11, im, NULL));
	break;
case I_LA:

	break;
case I_LB:
	add_instruction(new_i_inst(0x20, rs, rt, im, tg));
	break;
case I_LBU:
	add_instruction(new_i_inst(0x24, rs, rt, im, tg));
	break;
case I_LH:
	add_instruction(new_i_inst(0x21, rs, rt, im, tg));
	break;
case I_LHU:
	add_instruction(new_i_inst(0x25, rs, rt, im, tg));
	break;
case I_LW:
	add_instruction(new_i_inst(0x23, rs, rt, im, tg));
	break;
case I_LWCL:
	add_instruction(new_i_inst(0x31, rs, rt, im, tg));
	break;
case I_LWL:
	add_instruction(new_i_inst(0x22, rs, rt, im, tg));
	break;
case I_LWR:
	add_instruction(new_i_inst(0x26, rs, rt, im, tg));
	break;
case I_LD:

	break;
case I_LL:
	add_instruction(new_i_inst(0x30, rs, rt, im, tg));
	break;
case I_SB:
	add_instruction(new_i_inst(0x28, rs, rt, im, tg));
	break;
case I_SH:
	add_instruction(new_i_inst(0x29, rs, rt, im, tg));
	break;
case I_SW:
	add_instruction(new_i_inst(0x2b, rs, rt, im, tg));
	break;
case I_SWCL:
	add_instruction(new_i_inst(0x31, rs, rt, im, tg));
	break;
case I_SDCL:
	add_instruction(new_i_inst(0x3d, rs, rt, im, tg));
	break;
case I_SWL:
	add_instruction(new_i_inst(0x2a, rs, rt, im, tg));
	break;
case I_SWR:
	add_instruction(new_i_inst(0x2e, rs, rt, im, tg));
	break;
case I_SD:

	break;
case I_SC:
	add_instruction(new_i_inst(0x38, rs, rt, im, tg));
	break;
case I_MOVE:

	break;
case I_MFHI:
	add_instruction(new_r_inst(0x00, 0, 0, rd, 0, 0x10));
	break;
case I_MFLO:
	add_instruction(new_r_inst(0x00, 0, 0, rd, 0, 0x12));
	break;
case I_MTHI:
	add_instruction(new_r_inst(0x00, rs, 0, 0, 0, 0x11));
	break;
case I_MTLO:
	add_instruction(new_r_inst(0x00, rs, 0, 0, 0, 0x13));
	break;
case I_MFC0:
	add_instruction(new_r_inst(0x10, 0, rt, rd, 0, 0x00));
	break;
case I_MFC1:
	add_instruction(new_r_inst(0x11, 0, rt, rd, 0, 0x00));
	break;
case I_MFCL_D:

	break;
case I_MTC0:
	add_instruction(new_r_inst(0x10, 4, rt, rd, 0, 0x00));
	break;
case I_MTC1:
	add_instruction(new_r_inst(0x11, 4, rt, fs, 0, 0x00));
	break;
case I_MOVN:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x0b));
	break;
case I_MOVZ:
	add_instruction(new_r_inst(0x00, rs, rt, rd, 0, 0x0a));
	break;
case I_MOVF:
	add_instruction(new_r_inst(0x00, rs, c0, rd, 0, 0x01));
	break;
case I_MOVT:
	add_instruction(new_r_inst(0x00, rs, c1, rd, 0, 0x01));
	break;
case I_ABS_D:
	add_instruction(new_r_inst(0x11, 1, 0, rs, rd, 0x05));
	break;
case I_ABS_S:
	add_instruction(new_r_inst(0x11, 0, 0, rs, rd, 0x05));
	break;
case I_ADD_D:
	add_instruction(new_r_inst(0x11, 17, rt, rs, rd, 0x00));
	break;
case I_ADD_S:
	add_instruction(new_r_inst(0x11, 16, rt, rs, rd, 0x00));
	break;
case I_CEIL_W_D:
	add_instruction(new_r_inst(0x11, 17, 0, rs, rd, 0x0e));
	break;
case I_CEIL_W_S:
	add_instruction(new_r_inst(0x11, 16, 0, rs, rd, 0x0e));
	break;
case I_C_EQ_D:
	add_instruction(new_r_inst(0x11, 17, rt, rs, c0, 0x02));
	break;
case I_C_EQ_S:
	add_instruction(new_r_inst(0x11, 16, rt, rs, c0, 0x02));
	break;
case I_C_LE_D:
	add_instruction(new_r_inst(0x11, 17, rt, rs, c0, 0x0e));
	break;
case I_C_LE_S:
	add_instruction(new_r_inst(0x11, 16, rt, rs, c0, 0x0e));
	break;
case I_C_LT_D:
	add_instruction(new_r_inst(0x11, 17, rt, rs, c0, 0x0c));
	break;
case I_C_LT_S:
	add_instruction(new_r_inst(0x11, 16, rt, rs, c0, 0x0c));
	break;
case I_CVT_D_S:
	add_instruction(new_r_inst(0x11, 16, 0, rs, rd, 0x21));
	break;
case I_CVT_D_W:
	add_instruction(new_r_inst(0x11, 20, 0, rs, rd, 0x21));
	break;
case I_CVT_S_D:
	add_instruction(new_r_inst(0x11, 17, 0, rs, rd, 0x20));
	break;
case I_CVT_S_W:
	add_instruction(new_r_inst(0x11, 20, 0, rs, rd, 0x20));
	break;
case I_CVT_W_D:
	add_instruction(new_r_inst(0x11, 17, 0, rs, rd, 0x24));
	break;
case I_CVT_W_S:
	add_instruction(new_r_inst(0x11, 16, 0, rs, rd, 0x24));
	break;
case I_DIV_D:
	add_instruction(new_r_inst(0x11, 17, rt, rs, rd, 0x03));
	break;
case I_DIV_S:
	add_instruction(new_r_inst(0x11, 16, rt, rs, rd, 0x03));
	break;
case I_FLOOR_W_D:
	add_instruction(new_r_inst(0x11, 17, 0, rs, rd, 0x0f));
	break;
case I_FLOOR_W_S:
	add_instruction(new_r_inst(0x11, 16, 0, rs, rd, 0x0f));
	break;
case I_MOV_D:
	add_instruction(new_r_inst(0x11, 17, 0, rs, rd, 0x06));
	break;
case I_MOV_S:
	add_instruction(new_r_inst(0x11, 16, 0, rs, rd, 0x06));
	break;
case I_MOVF_D:
	add_instruction(new_r_inst(0x11, 17, c0, rs, rd, 0x11));
	break;
case I_MOVF_S:
	add_instruction(new_r_inst(0x11, 16, c0, rs, rd, 0x11));
	break;
case I_MOVT_D:
	add_instruction(new_r_inst(0x11, 17, c1, rs, rd, 0x11));
	break;
case I_MOVT_S:
	add_instruction(new_r_inst(0x11, 16, c1, rs, rd, 0x11));
	break;
case I_MOVN_D:
	add_instruction(new_r_inst(0x11, 17, rt, rs, rd, 0x13));
	break;
case I_MOVN_S:
	add_instruction(new_r_inst(0x11, 16, rt, rs, rd, 0x13));
	break;
case I_MOVZ_D:
	add_instruction(new_r_inst(0x11, 17, rt, rs, rd, 0x12));
	break;
case I_MOVZ_D:
	add_instruction(new_r_inst(0x11, 16, rt, rs, rd, 0x12));
	break;
case I_MUL_D:
	add_instruction(new_r_inst(0x11, 17, rt, rs, rd, 0x02));
	break;
case I_MUL_S:
	add_instruction(new_r_inst(0x11, 16, rt, rs, rd, 0x02));
	break;
case I_NEG_D:
	add_instruction(new_r_inst(0x11, 17, 0, rs, rd, 0x07));
	break;
case I_NEG_S:
	add_instruction(new_r_inst(0x11, 16, 0, rs, rd, 0x07));
	break;
case I_ROUND_W_D:
	add_instruction(new_r_inst(0x11, 17, 0, rs, rd, 0x0c));
	break;
case I_ROUDN_W_S:
	add_instruction(new_r_inst(0x11, 16, 0, rs, rd, 0x0c));
	break;
case I_SQRT_D:
	add_instruction(new_r_inst(0x11, 17, 0, rs, rd, 0x04));
	break;
case I_SQRT_S:
	add_instruction(new_r_inst(0x11, 16, 0, rs, rd, 0x04));
	break;
case I_SUB_D:
	add_instruction(new_r_inst(0x11, 17, rt, rs, rd, 0x01));
	break;
case I_SUB_S:
	add_instruction(new_r_inst(0x11, 16, rt, rs, rd, 0x01));
	break;
case I_TRUNC_W_D:
	add_instruction(new_r_inst(0x11, 17, 0, rs, rd, 0x0d));
	break;
case I_TRUNC_W_S:
	add_instruction(new_r_inst(0x11, 16, 0, rs, rd, 0x0d));
	break;
case I_ERET:
	add_instruction(new_r_inst(0x00, 16, 0, 0, 0, 0x18));
	break;
case I_SYSCALL:
	add_instruction(new_r_inst(0x00, 0, 0, 0, 0, 0x0c));
	break;
case I_NOP:
	add_instruction(new_r_inst(0x00, 0, 0, 0, 0, 0x00));
	break;
