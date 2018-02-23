/*
	Initializes the interstage registers
*/
P_Regs* init_interstage_regs() {
	P_Regs* interstage_regs = (P_Regs*)malloc(sizeof(P_Regs));
	check_alloc((void*)interstage_regs);
	interstage_regs->p_if = (P_IF*)malloc(sizeof(P_IF));
	check_alloc((void*)interstage_regs->p_if);
	interstage_regs->p_id = (P_ID*)malloc(sizeof(P_ID));
	check_alloc((void*)interstage_regs->p_id);
	interstage_regs->p_exe = (P_EXE*)malloc(sizeof(P_EXE));
	check_alloc((void*)interstage_regs->p_exe);
	interstage_regs->p_mem = (P_MEM*)malloc(sizeof(P_MEM));
	check_alloc((void*)interstage_regs->p_mem);
	return interstage_regs;
}

/*
	Copies the interstage registers from source to the destination
*/
void copy_interstage_regs(P_Regs* dest, P_Regs* src) {
	memcpy(dest, src, sizeof(P_Regs));
}

/*
	Frees the interstage registers
*/
void free_interstage_registers(P_Regs* interstage_regs) {
	free(interstage_regs->p_if);
	free(interstage_regs->p_id);
	free(interstage_regs->p_exe);
	free(interstage_regs->p_mem);
	free(interstage_regs);
}