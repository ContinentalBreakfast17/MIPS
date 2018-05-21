#define I_REG 		0
#define F_REG 		1
#define C_FLAG 		2
#define REG_COUNT	32
#define FLAG_COUNT	8

typedef union mips_data {
	unsigned long long	i;
	double 				f;
	char 				c;
} Data;

typedef struct mips_registers {
	int* 				i_regs;
	float* 				f_regs;
	char* 				c_flags;
} Regs;

Regs* 	init_registers();
void 	set_reg(Regs* registers, unsigned int reg_type, unsigned int size, Data value);
Data 	get_reg(Regs* registers, unsigned int reg_type, unsigned int size, unsigned int reg);