#define CHOOSE_REGISTER_FILE (fp) ? (reg_file->f_regs) : (reg_file->regs)

/*
	Creates a new list of ROB entries to be used for the register file
*/
Buffer_Entry** new_entry_list(int size) {
	Buffer_Entry** list = (Buffer_Entry**)malloc(sizeof(Buffer_Entry*)*size);
	check_alloc((void*)list);
	int i;
	for(i = 0; i < size; i++) {
		list[i] = NULL;
	}
	return list;
}

/*
	Initializes the register file
	Integer registers have 34 rather than 32 to account for high/low
*/
Register_File* 	init_register_file() {
	Register_File* reg_file = (Register_File*)malloc(sizeof(Register_File));
	check_alloc((void*)reg_file);
	reg_file->regs = new_entry_list(34);
	reg_file->f_regs = new_entry_list(32);
	return reg_file;
}

/*
	Returns the ROB entry associated with the register file at the given index
*/
Buffer_Entry* access_register_file(Register_File* reg_file, int fp, int index) {
	Buffer_Entry** regs = CHOOSE_REGISTER_FILE;
	return regs[index];
}

/*
	Stores the ROB entry in the register file at the given index
*/
void update_register_file(Register_File* reg_file, Buffer_Entry* entry) {
	int fp = entry->dest->fp;
	Buffer_Entry** regs = CHOOSE_REGISTER_FILE;
	regs[entry->dest->reg] = entry;

	if(entry->dest->size == sizeof(long long)) {
		regs[entry->dest->reg+1] = entry;
	}
}

/*
	Clears the register file of the entry if it is still there
*/
void clear_register_file(Register_File* reg_file, Buffer_Entry* entry) {
	int fp = entry->fp;
	Buffer_Entry** regs = CHOOSE_REGISTER_FILE;
	if(regs[entry->dest->reg] == entry) {
		regs[entry->dest->reg] = NULL;
	}

	if(entry->dest->size == sizeof(long long) && regs[entry->dest->reg+1] == entry) {
		regs[entry->dest->reg+1] = NULL;
	}
}