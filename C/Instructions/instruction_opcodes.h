/*
	R Instructions
*/
#define I_OP_ADD						0x20
#define I_OP_ADDU						0x21
#define I_OP_AND						0x24
#define I_OP_CLO						0x21
#define I_OP_CLZ						0x20
#define I_OP_DIV						0x1a
#define I_OP_DIVU						0x1b
#define I_OP_MULT						0x18
#define I_OP_MULTU						0x19
#define I_OP_MUL 						0x02
#define I_OP_MADD						0x00
#define I_OP_MADDU						0x01
#define I_OP_MSUB						0x04
#define I_OP_MSUBU						0x05
#define I_OP_NOR						0x27
#define I_OP_OR 						0x25
#define I_OP_SLL						0x00
#define I_OP_SLLV						0x04
#define I_OP_SRA						0x03
#define I_OP_SRAV						0x07
#define I_OP_SRL						0x02
#define I_OP_SRLV						0x06
#define I_OP_SUB 						0x22
#define I_OP_SUBU 						0x23
#define I_OP_XOR						0x26
#define I_OP_SLT						0x2a
#define I_OP_SLTU						0x2b
#define I_OP_JALR						0x09
#define I_OP_JR 						0x08
#define I_OP_TEQ						0x34
#define I_OP_TNE 						0x36
#define I_OP_TGE						0x30
#define I_OP_TGEU						0x31
#define I_OP_TLT						0x32
#define I_OP_TLTU						0x33
#define I_OP_MFHI						0x10
#define I_OP_MFLO						0x12
#define I_OP_MTHI						0x11
#define I_OP_MTLO						0x13
#define I_OP_MFC0						0x00
#define I_OP_MTC0 						0x04
#define I_OP_MOVN						0x0b
#define I_OP_MOVZ						0x0a
#define I_OP_MOVF						0x00
#define I_OP_MOVT						0x01


/*
	I Instructions
*/
#define I_OP_ADDI						0x08
#define I_OP_ADDIU						0x09
#define I_OP_ANDI						0x0c
#define I_OP_ORI						0x0d
#define I_OP_XORI						0x0e
#define I_OP_LUI						0x0f
#define I_OP_SLTI						0x0a
#define I_OP_SLTIU						0x0b
#define I_OP_BCLF						0x12
#define I_OP_BCLT						0x13
#define I_OP_BEQ						0x04
#define I_OP_BGEZ						0x01
#define I_OP_BGEZAL						0x11
#define I_OP_BGTZ						0x07
#define I_OP_BLEZ						0x06
#define I_OP_BLTZAL						0x10
#define I_OP_BLTZ 						0x00
#define I_OP_BNE						0x05
#define I_OP_TEQI						0x0c
#define I_OP_TNEI						0x0e
#define I_OP_TGEI						0x08
#define I_OP_TGEIU						0x09
#define I_OP_TLTI						0x0a
#define I_OP_TLTIU						0x0b
#define I_OP_LB 						0x20
#define I_OP_LBU						0x24
#define I_OP_LH							0x21
#define I_OP_LHU						0x25
#define I_OP_LW							0x23
#define I_OP_LWC1						0x31
#define I_OP_LWL						0x22
#define I_OP_LWR						0x26
#define I_OP_LL 						0x30
#define I_OP_SB 						0x28
#define I_OP_SH 						0x29
#define I_OP_SW							0x2b
#define I_OP_SWC1						0x31
#define I_OP_SDC1						0x3d
#define I_OP_SWL						0x2a
#define I_OP_SWR						0x2e
#define I_OP_SC 						0x38

/*
	J Instructions
*/
#define I_OP_J							0x02
#define I_OP_JAL						0x03

/*
	F Instructions
*/
#define I_OP_F_MFC1						0x00
#define I_OP_F_MTC1						0x04
#define I_OP_F_ABS						0x05
#define I_OP_F_ADD 						0x00
#define I_OP_F_CEIL_W					0x0e
#define I_OP_F_C_EQ						0x02
#define I_OP_F_C_LE 					0x0e
#define I_OP_F_C_LT						0x0c
#define I_OP_F_CVT_D					0x21
#define I_OP_F_CVT_S					0x20
#define I_OP_F_CVT_W					0x24
#define I_OP_F_DIV						0x03
#define I_OP_F_FLOOR_W					0x0f
#define I_OP_F_MOV						0x06
#define I_OP_F_MOVF						0x00
#define I_OP_F_MOVT						0x01
#define I_OP_F_MOVN						0x13
#define I_OP_F_MOVZ						0x12
#define I_OP_F_MUL						0x02
#define I_OP_F_NEG						0x07
#define I_OP_F_ROUND_W					0x0c
#define I_OP_F_SQRT						0x04
#define I_OP_F_SUB						0x01
#define I_OP_F_TRUNC_W					0x0d			