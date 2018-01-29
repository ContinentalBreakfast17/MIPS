/*
	Allocates an array to contain the registers and initializes them to contain 0's
	Stack pointer and global pointer are initialized to top/bottom of data segment, respectively
	Register array contains high and low at the end to reduce need for extra functions
*/
int* init_registers() {
	int* registers = (int*)malloc(sizeof(int)*34);
	check_malloc(registers);
	memset(registers, 0, sizeof(int)*34);
	set_reg(R_SP, 0x7fffffff);
	set_reg(R_FP, 0x7fffffff);
	set_reg(R_GP, 0x10000000);
	return registers;
}

/*
	Sets the given register to the given value, then returns the result
	Requests to set forbidden registers (such as $0) will be ignored
*/
int set_reg(int* registers, unsigned int reg, int val) {
	if(reg == R_ZERO || reg == R_K0 || reg == R_K1) 
		return 0;
	return registers[reg] = val;
}

/* 
	Returns the value of the given register
	May want to block kernel registers?
*/
int get_reg(int* registers, unsigned int reg) {
	return registers[reg];
}