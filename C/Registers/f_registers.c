/*
	Allocates an array to contain the floating point registers and initializes them to contain 0's
*/
float* init_registers() {
	float* f_registers = (float*)malloc(sizeof(float)*32);
	check_malloc(f_registers);
	memset(f_registers, 0, sizeof(float)*32);
	return f_registers;
}

/*
	Sets the given register to the given value, then returns the result
*/
float set_reg(float* f_registers, unsigned int reg, float val) {
	return f_registers[reg] = val;
}

/* 
	Returns the value of the given register
*/
float get_reg(float* f_registers, unsigned int reg) {
	return f_registers[reg];
}