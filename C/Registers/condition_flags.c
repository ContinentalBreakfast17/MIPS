/*
	Initializes the 8 condition flags
*/
char* init_condition_flags() {
	char* condition_flags = (char*)malloc(sizeof(char)*8);
	check_alloc((void*)condition_flags);
	return condition_flags;
}

/*
	Returns the nth condition flag or -1 if n is invalid
*/
char get_condition_flag(char* condition_flags, unsigned int n) {
	if(n >= 0 && n < 8)
		return condition_flags[n];
	return -1;
}