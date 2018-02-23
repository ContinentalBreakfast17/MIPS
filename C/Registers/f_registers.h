#define R_F0	0
#define R_F1	1
#define R_F2	2
#define R_F3	3
#define R_F4	4
#define R_F5	5
#define R_F6	6
#define R_F7	7
#define R_F8	8
#define R_F9	9
#define R_F10	10
#define R_F11	11
#define R_F12	12
#define R_F13	13
#define R_F14	14
#define R_F15	15
#define R_F16	16
#define R_F17	17
#define R_F18	18
#define R_F19	19
#define R_F20	20
#define R_F21	21
#define R_F22	22
#define R_F23	23
#define R_F24	24
#define R_F25	25
#define R_F26	26
#define R_F27	27
#define R_F28	28
#define R_F29	29
#define R_F30	30
#define R_F31	31

float* init_f_registers();
float get_f_reg(float* f_registers, unsigned int reg);
float set_f_reg(float* f_registers, unsigned int reg, float val);