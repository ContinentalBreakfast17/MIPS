#define R_ZERO 	0
#define R_AT 	1
#define R_V0	2
#define R_V1 	3
#define R_A0 	4
#define R_A1 	5
#define R_A2 	6
#define R_A3	7
#define R_T0	8
#define R_T1	9
#define R_T2	10
#define R_T3	11
#define R_T4	12
#define R_T5	13
#define R_T6	14
#define R_T7	15
#define R_S0	16
#define R_S1	17
#define R_S2	18
#define R_S3	19
#define R_S4	20
#define R_S5	21
#define R_S6	22
#define R_S7	23
#define R_T8 	24
#define R_T9	25
#define R_K0	26
#define R_K1	27
#define R_GP	28
#define R_SP	29
#define R_FP	30
#define R_RA	31
#define R_HI	32
#define R_LO	33

int* init_registers();
int get_reg(int* registers, unsigned int reg);
int set_reg(int* registers, unsigned int reg, int val);