#define CHECK_INTEGER_OVERFLOW 				if(overflow && (arg1 > 0 && arg2 > 0 && result < 0) || (arg1 < 0 && arg2 < 0 && result > 0)) return ALU_INTEGER_OVERFLOW
#define CHECK_LONG_INTEGER_OVERFLOW 		if(overflow && (arg1 > 0 && arg2 > 0 && long_result < 0) || (arg1 < 0 && arg2 < 0 && long_result > 0)) return ALU_INTEGER_OVERFLOW
#define CHECK_SUB_INTEGER_OVERFLOW 			if(overflow && ((result < arg1) != (arg2 > 0))) return ALU_INTEGER_OVERFLOW

int syscall(Hardware* hardware);

int compute(ALU_Data* data, Hardware* hardware) {
	int arg1 = data->arg1.i;
	int arg2 = data->arg2.i;
	unsigned char overflow = data->overflow;

	if(data->src == ALU_IM_SRC) arg2 = data->im;
	else if(data->src == ALU_SH_SRC) arg2 = data->shamt;
	unsigned int result = 0;
	unsigned int long_result = 0;

	switch(data->opcode) {
		/*
			Begin arithmetic functions
		*/
		case ALU_ADD:
			result = arg1 + arg2;
			CHECK_INTEGER_OVERFLOW;
			break;
		case ALU_AND:
			result = arg1 & arg2;
			break;
		case ALU_CLO:
			unsigned int counter = 0x80000000;
			while(arg1 & counter) {
				result += 1;
				counter >> 2;
			}
			break;
		case ALU_CLZ:
			unsigned int counter = 0x80000000;
			while(!(arg1 & counter)) {
				result += 1;
				counter >> 2;
			}
			break;
		case ALU_DIV:
			result = arg1 / arg2;
			CHECK_INTEGER_OVERFLOW;
			set_reg(hardware->registers, R_LO, arg1 % arg2);
			break;
		case ALU_MULT:
			long_result = arg1 * arg2;
			CHECK_LONG_INTEGER_OVERFLOW;
			set_reg(hardware->registers, R_HI, int((long_result & 0xffffffff00000000)>>32));
			set_reg(hardware->registers, R_LO, int(long_result & 0x00000000ffffffff));
			break;
		case ALU_MUL:
			long_result = arg1 * arg2;
			result = int(long_result & 0x00000000ffffffff);
			break;
		case ALU_MADD:
			long_result = arg1 * arg2;
			CHECK_LONG_INTEGER_OVERFLOW;
			arg1 = get_reg(hardware->registers, R_HI);
			arg2 = int((long_result & 0xffffffff00000000)>>32);
			result = arg1 + arg2;
			CHECK_INTEGER_OVERFLOW;
			set_reg(hardware->registers, R_HI, result);
			arg1 = get_reg(hardware->registers, R_LO);
			arg2 = int(long_result & 0x00000000ffffffff);
			result = arg1 + arg2;
			CHECK_INTEGER_OVERFLOW;
			set_reg(hardware->registers, R_LO, result);
			break;
		case ALU_MSUB:
			long_result = arg1 * arg2;
			CHECK_LONG_INTEGER_OVERFLOW;
			arg1 = get_reg(hardware->registers, R_HI);
			arg2 = int((long_result & 0xffffffff00000000)>>32);
			result = arg1 - arg2;
			CHECK_SUB_INTEGER_OVERFLOW;
			set_reg(hardware->registers, R_HI, result);
			arg1 = get_reg(hardware->registers, R_LO);
			arg2 = int(long_result & 0x00000000ffffffff);
			result = arg1 - arg2;
			CHECK_SUB_INTEGER_OVERFLOW;
			set_reg(hardware->registers, R_LO, result);
			break;
		case ALU_NOR:
			result = !(arg1|arg2);
			break;
		case ALU_OR:
			result = arg1|arg2;
			break;
		case ALU_SLL:
			result = arg1 << arg2;
			break;
		case ALU_SRA:
			result = arg1 << arg2;
			break;
		case ALU_SRL:
			result = unsigned int(arg1) << arg2;
			break;
		case ALU_SUB:
			result = arg1 - arg2;
			CHECK_SUB_INTEGER_OVERFLOW;
			break;
		case ALU_XOR:
			result = arg1 ^ arg2;
			break;

		/*
			Begin constant manipulating instructions
		*/
		case ALU_LUI:
			result += arg2 << 16;
			break;

		/*
			Begin comparison instructions
		*/
		case ALU_SLT:
			result = arg1 < arg2;
			break;
		case ALU_SLTU:
			result = unsigned int(arg1) < unsigned int(arg2);
			break;

		/*
			Begin branch instructions
			Branches are handled in the ID stage so nothing needs to be done here
		*/
		case ALU_B:
			break;

		/*
			Begin jump instructions
		*/
		case ALU_J:
			result = 0xff000000 + (data->jump_target << 2);
			break;
		case ALU_JAL:
			result = 0xff000000 + (data->jump_target << 2);
			set_reg(hardware->registers, R_RA, pc+4);
			break;
		case ALU_JALR:
			result = arg1;
			set_reg(hardware->registers, data->rd, pc+4);
			break;
		case ALU_JR:
			result = arg1;
			break;
		
		/*
			Begin trap instructions
			Not currently supported
		*/
		case ALU_T:
			break;

		/*
			Begin load instructions
		*/
		case ALU_L:
			result = data->pc + arg2;
			break;

		/*
			Begin store instructions
		*/
		case ALU_S:
			result = data->pc + arg2;
			break;

		/*
			Begin data movement instructions
		*/
		case ALU_MFHI:
			result = get_reg(hardware->registers, R_HI);
			break;
		case ALU_MFLO:
			result = get_reg(hardware->registers, R_LO);
			break;
		case ALU_MTHI:
			result = set_reg(hardware->registers, R_HI, arg1);
			break;
		case ALU_MTLO:
			result = set_reg(hardware->registers, R_LO, arg1);
			break;
		case ALU_MOVC: // move to/from coprocessor, make sure to set these up right in instruction_decipher
			result = arg1;
			break;
		case ALU_MOVN:
			result = (arg2 == 0) ? (get_reg(hardware->registers, data->rd)) : (arg1);
			break;
		case ALU_MOVZ:
			result = (arg2 != 0) ? (get_reg(hardware->registers, data->rd)) : (arg1);
			break;
		case ALU_MOVF:
			result = (get_condition_flag(hardware->condition_flags, data->cc) == 0) ? (arg1) : (get_reg(hardware->registers, data->rd));
			// else set reg_wr = 0 !
			break;
		case ALU_MOVT:
			result = (get_condition_flag(hardware->condition_flags, data->cc) == 1) ? (arg1) : (get_reg(hardware->registers, data->rd));
			break;

		/*
			Begin exception/interrupt instructions
			Exception return and break currently not handled
		*/
		case ALU_ERET:
			break;
		case ALU_SYSCALL:
			result = syscall(hardware);
			break;
		case ALU_BREAK:
			break;
		case ALU_NOP:
			break;
	}

	data->retval.i = result;
	return 0;
}

int compute_float(int control, int src, float arg1, float arg2, int im, unsigned int pc, (void*)retval) {
	switch(control) {
		
	}
	return 0;
}

int syscall(Hardware* hardware) {
	switch(get_reg(hardware->registers, R_V0)) {
		case 1:
			printf("%d", get_reg(hardware->registers, R_A0));
			break;
		case 2:
			printf("%f", get_f_reg(hardware->f_registers, R_F12));
			break;
		case 3:
			printf("%lf", get_f_reg(hardware->f_registers, R_F12));
			break;
		case 4:
			printf("%s", &hardware->memory[get_reg(hardware->registers, R_A0)]);
			break;
		case 5:
			int val;
			scanf("%d", &val);
			set_reg(hardware->registers, R_V0, val);
			break;
		case 6:
			float val;
			scanf("%f", &val);
			set_f_reg(hardware->registers, R_F0, val);
			break;
		case 7:
			double val;
			scanf("%lf", &val);
			// can't store double into float reg!
			set_f_reg(hardware->registers, R_F0, val);
			break;
		case 8:
			fgets(&hardware->memory[get_reg(hardware->registers, R_A0)], get_reg(hardware->registers, R_A1), stdin);
			break;
		case 9:
			unsigned int address = get_reg(hardware->registers, R_GP) + get_reg(hardware->registers, R_A0);
			set_reg(hardware->registers, R_V0, get_reg(hardware->registers, R_GP));
			set_reg(hardware->registers, R_GP, address);
			break;
		case 10:
			return TERMINATE;
		case 11:
			printf("%c", (char)(get_reg(hardware->registers, R_A0) & 0x000000ff));
			break;
		case 12:
			char val;
			scanf("%c", &val);
			set_reg(hardware->registers, R_V0, val);
			break;
		case 13:
			int fd = open(&hardware->memory[get_reg(hardware->registers, R_A0)], get_reg(hardware->registers, R_A1), get_reg(hardware->registers, R_A2));
			set_reg(hardware->registers, R_V0, fd);
			break;
		case 14:
			int n = read(get_reg(hardware->registers, R_A0), &hardware->memory[get_reg(hardware->registers, R_A1)], get_reg(hardware->registers, R_A2));
			set_reg(hardware->registers, R_V0, n);
			break;
		case 15:
			int n = write(get_reg(hardware->registers, R_A0), &hardware->memory[get_reg(hardware->registers, R_A1)], get_reg(hardware->registers, R_A2));
			set_reg(hardware->registers, R_V0, n);
			break;
		case 16:
			close(get_reg(hardware->registers, R_A0));
			break;
		case 17:
			return TERMINATE_CODE;
	}
	return 0;
}