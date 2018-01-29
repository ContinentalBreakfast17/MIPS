#define F0	0
#define F1	1
#define F2	2
#define F3	3
#define F4	4
#define F5	5
#define F6	6
#define F7	7
#define F8	8
#define F9	9
#define F10	10
#define F11	11
#define F12	12
#define F13	13
#define F14	14
#define F15	15
#define F16	16
#define F17	17
#define F18	18
#define F19	19
#define F20	20
#define F21	21
#define F22	22
#define F23	23
#define F24	24
#define F25	25
#define F26	26
#define F27	27
#define F28	28
#define F29	29
#define F30	30
#define F31	31

float* init_f_registers();
float get_f_reg(float* f_registers, unsigned int reg);
float set_f_reg(float* f_registers, unsigned int reg, float val);