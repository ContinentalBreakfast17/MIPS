/*
	Allocates an array to contain the registers and initializes them to contain 0's
	Stack pointer and global pointer are initialized to top/bottom of data segment, respectively
	Register array contains high and low at the end to reduce need for extra functions
*/
int* init_i_registers() {
	int* i_registers = (int*)malloc(sizeof(int)*(REG_COUNT + 2));
	check_alloc((void*)i_registers);
	memset(i_registers, 0, sizeof(int)*(REG_COUNT + 2));
	set_reg(R_SP, MEM_SIZE-1);
	set_reg(R_FP, MEM_SIZE-1);
	set_reg(R_GP, INIT_GP);
	return i_registers;
}

/* 
	Returns the value of the given register
	May want to block kernel registers?
*/
int get_i_reg(int* i_registers, unsigned int reg) {
	return i_registers[reg];
}

/*
	Sets the given register to the given value
	Requests to set forbidden registers (such as $0) will be ignored
*/
void set_i_reg(int* i_registers, unsigned int reg, int val) {
	if(reg == R_ZERO || reg == R_K0 || reg == R_K1) 
		return;
	i_registers[reg] = val;
}

/*
	Allocates an array to contain the floating point registers and initializes them to contain 0's
*/
float* init_f_registers() {
	float* f_registers = (float*)malloc(sizeof(float)*REG_COUNT);
	check_alloc((void*)f_registers);
	memset(f_registers, 0, sizeof(float)*REG_COUNT);
	return f_registers;
}

/* 
	Returns the value of the given register
*/
float get_f_reg(float* f_registers, unsigned int reg) {
	return f_registers[reg];
}

/*
	Sets the given register to the given value
*/
void set_f_reg(float* f_registers, unsigned int reg, float val) {
	f_registers[reg] = val;
}

/*
	Initializes the 8 condition flags
*/
char* init_condition_flags() {
	char* condition_flags = (char*)malloc(sizeof(char)*FLAG_COUNT);
	check_alloc((void*)condition_flags);
	return condition_flags;
}

/*
	Returns the nth condition flag
*/
char get_condition_flag(char* condition_flags, unsigned int n) {
	return condition_flags[n];
}

/*
	Sets the nth condition flag
*/
void set_condition_flag(char* condition_flags, unsigned int n, char val) {
	condition_flags[n] = val;
}

/*
	Initializes all registers
*/
Regs* init_registers() {
	Regs* registers = (Regs*)malloc(sizeof(Regs));
	check_alloc((void*)registers);
	registers->i_regs = init_i_registers();
	registers->f_regs = init_f_registers();
	registers->c_flags = init_condition_flags();
	return registers;
}

/*
	Returns the data of a given register
*/
Data get_reg(Regs* registers, unsigned int reg_type, unsigned int size, unsigned int reg) {
	Data result;
	switch(reg_type) {
		case C_FLAG:
			result.c = get_condition_flag(registers->c_flags, reg);
			break;
		case I_REG:
			result.i = get_i_reg(registers->i_regs, reg);
			if(size == sizeof(long long)) {
				result.i = result.i | (get_i_reg(registers->i_regs, reg+1) << 32);
			}
			break;
		case F_REG:
			result.f = get_f_reg(registers->f_regs, reg);
			if(size == sizeof(long long)) {
				result.f = result.f | (get_f_reg(registers->f_regs, reg+1) << 32);
			}
			break;
	}
}

/*
	Sets the data of a given register
	TODO: see if that float storage actually works as intended
*/
void set_reg(Regs* registers, unsigned int reg_type, unsigned int size, Data value) {
	switch(reg_type) {
		case C_FLAG:
			set_condition_flag(registers->c_flags, reg, value.c);
			break;
		case I_REG:
			set_i_reg(registers->i_regs, reg, value.i & 0xffff);
			if(size == sizeof(long long)) {
				set_i_reg(registers->i_regs, reg+1, (value.i & 0xffff0000) >> 32);
			}
			break;
		case F_REG:
			if(size == sizeof(long long)) {
				set_f_reg(registers->f_regs, reg, value.f & 0xffff);
				set_f_reg(registers->f_regs, reg+1, (value.f & 0xffff0000) >> 32);
			} else {
				set_f_reg(registers->f_regs, reg, (float)value.f);
			}
			break;
	}
}