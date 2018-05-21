typedef struct register_file {
	Buffer_Entry** 	regs;
	Buffer_Entry**	f_regs;
} Register_File;

Register_File* 		init_register_file();
Buffer_Entry* 		access_register_file(Register_File* reg_file, int fp, int index);
void		 		update_register_file(Register_File* reg_file, int fp, int index, Buffer_Entry* entry);
void		 		clear_register_file(Register_File* reg_file, int fp, int index, Buffer_Entry* entry);