
int decipher_instruction(unsigned int inst, P_Regs* tmp_interstage_regs, ALU_Data* alu_data, int* branch) {
	unsigned int bits_1_to_6 = unsigned int(inst & 0xfc000000) >> 26;
	unsigned int bits_7_to_11 = unsigned int(inst & 0x03e00000) >> 21;
	unsigned int bits_12_to_16 = unsigned int(inst & 0x001f0000) >> 16;
	unsigned int bits_17_to_21 = unsigned int(inst & 0x0000f800) >> 11;
	unsigned int bits_22_to_26 = unsigned int(inst & 0x000007c0) >> 6;
	unsigned int bits_27_to_32 = unsigned int(inst & 0x0000003f);

	
}