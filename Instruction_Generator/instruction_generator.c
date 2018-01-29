#define H_R_CODES 	"Output/r_codes.h"
#define H_OPCODES	"Output/opcodes.h"
#define H_I_TYPES 	"Output/instruction_types.h"
#define C_OUTPUT	"Output/output.c"
#define Y_OUTPUT 	"Output/yacc_instruction.y"
#define INPUT		"instruction_set.csv"
#define BUFFER_SZ 	70
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// BEGIN BS FOR READING FILE INTO AN ARRAY
// SHOULDN'T HAVE DONE THIS SHIT IN C

void check_file(FILE* f, int n) {
	if(f == NULL) {
		printf("Could not access file %d\n", n);
		exit(1);
	}
}

int is_ws(char c) {
	return (c == ' ' || c == '\n' || c == '\t');
}

char* trim_space(char* s) {
	int i = strlen(s) - 1;
	while(is_ws(s[i]) && i > 0) s[i--] = 0;
	return s;
}

int next_word(char* s) {
	int len = strlen(s);
	int i = 0;
	while(i < len && !is_ws(s[i])) i++;
	if(i == len) return -1;
	while(i < len && is_ws(s[i])) i++;
	if(i == len) return -1;
	return i;
}

char** line_to_array(char* s) {
	int n, end = 0, i = 0, count = 1, sz = 16;
	char** array = (char**)malloc(sizeof(char*)*sz);
	while(!end) {
		n = next_word(s+i);
		if(n == -1) {
			end = 1;
			n = strlen(s)-i;
		}
		char* word = malloc(n+1);
		word[n] = 0;
		for(int j = 0; j < n; j++)
			word[j] = s[i+j];
		array[count++] = trim_space(word);
		i += n;
	}
	array[0] = malloc(1);
	*(array[0]) = (char)count;
	return array;
}

void free_array(char** array) {
	char count = *(array[0]);
	for(int i = 0; i < count; i++)
		free(array[i]);
	free(array);
}

int read_line(FILE* input, char* line) {
	char c;
	int i = 0;
	memset(line, 0, BUFFER_SZ);
	while((c = fgetc(input)) != '\n') {
		if(c == EOF && i == 0) return 0;
		else if(c == EOF) return 1;
		else line[i++] = c;
	}
	return 1;
}

// END FILE SHIT

char* to_upper(char* s) {
	int n = strlen(s);
	for(int i = 0; i < n; i++) {
		if(s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
	}
	return s;
}

int htoi(char* s) {
	if(strlen(s) >= 3 && s[1] == 'x')
		return (int)strtol(s+2, NULL, 16);
	return (int)strtol(s, NULL, 16);
}

char* make_space(char* space, int len) {
	for(int i = 0; i < 20 - len; i++)
		space[i] = ' ';
	space[20-len] = 0;
	return space;
}

void add_r_code(int* list, int code, FILE* r_codes) {
	int i = 0;
	while(list[i] != 0)
		if(list[i++] == code) return;
	list[i] = code;
	fprintf(r_codes, "%d: %d\n", i+2, code);
}

void print_inst_file(char* path, char* inst, char type, int inst_count) {
	char buf[64];
	sprintf(buf, "%s/%s.c", path, inst);
	if(access(buf, F_OK) == -1) {
		FILE* f = fopen(buf, "w+");
		check_file(f, inst_count+6);
		fprintf(f, "int %s(%c_Data* this) {\n\t\n}\n", inst, type);
	}
}

void print_yacc(char** chunked, FILE* yacc) {
	fprintf(yacc, "| %s \n{\n\t\n}\n", to_upper(chunked[1]));
}

void print_r_instruction(char** chunked, int inst_count, int* r_code_list, FILE* output, FILE* i_types, FILE* opcodes, FILE* r_codes) {
	print_inst_file("../C/Instructions/Register", chunked[1], 'R', inst_count);
	char* op_name = to_upper(chunked[1]);
	char space[strlen(op_name) + 1];
	make_space(space, strlen(op_name) + 1);
	int op1 = htoi(chunked[3]);
	int op2 = htoi(chunked[8]);

	fprintf(output, "case I_%s:\n\tadd_instruction(new_r_inst(%s, %s, %s, %s, %s, %s));\n\tbreak;\n", 
		op_name, chunked[3], chunked[4], chunked[5], chunked[6], chunked[7], chunked[8]);
	fprintf(i_types, "#define I_%s%s%d\n", 
		op_name, space, inst_count);
	fprintf(opcodes, "#define I_%s_OP_1%s%d\n#define I_%s_OP_2%s%d\n", 
		op_name, space, op1, op_name, space, op2);
	int strval, n = 3;
	for(int i = 4; i < 7; i++) {
		if((strval = atoi(chunked[i])) != 0)
			fprintf(opcodes, "#define I_%s_OP_%d%s%d\n", op_name, n++, space, strval);
	}
	if(op1 != 0)
		add_r_code(r_code_list, op1, r_codes);
}

void print_i_instruction(char** chunked, int inst_count, FILE* output, FILE* i_types, FILE* opcodes) {
	print_inst_file("../C/Instructions/Immediate", chunked[1], 'I', inst_count);
	char* op_name = to_upper(chunked[1]);
	char space[strlen(op_name) + 1];
	make_space(space, strlen(op_name) + 1);
	int op = htoi(chunked[3]);

	if(strcmp(chunked[6], "im") == 0)
		fprintf(output, "case I_%s:\n\tadd_instruction(new_i_inst(%s, %s, %s, %s, NULL));\n\tbreak;\n", 
			op_name, chunked[3], chunked[4], chunked[5], chunked[6]);
	else
		fprintf(output, "case I_%s:\n\tadd_instruction(new_i_inst(%s, %s, %s, 0, %s));\n\tbreak;\n", 
			op_name, chunked[3], chunked[4], chunked[5], chunked[6]);
	fprintf(i_types, "#define I_%s%s%d\n", 
		op_name, space, inst_count);
	fprintf(opcodes, "#define I_%s_OP_1%s%d\n", 
		op_name, space, op);
	int strval, n = 2;
	for(int i = 4; i < 6; i++) {
		if((strval = atoi(chunked[i])) != 0)
			fprintf(opcodes, "#define I_%s_OP_%d%s%d\n", op_name, n++, space, strval);

	}
}

void print_j_instruction(char** chunked, int inst_count, FILE* output, FILE* i_types, FILE* opcodes) {
	print_inst_file("../C/Instructions/Jump", chunked[1], 'J', inst_count);
	char* op_name = to_upper(chunked[1]);
	char space[strlen(op_name) + 1];
	make_space(space, strlen(op_name) + 1);
	int op = htoi(chunked[3]);

	fprintf(output, "case I_%s:\n\tadd_instruction(new_j_inst(%s, %s));\n\tbreak;\n", 
		op_name, chunked[3], chunked[4]);
	fprintf(i_types, "#define I_%s%s%d\n", 
		op_name, space, inst_count);
	fprintf(opcodes, "#define I_%s_OP_1%s%d\n", 
		op_name, space, op);
}

void print_m_instruction(char** chunked, int inst_count, FILE* output, FILE* i_types, FILE* opcodes) {
	print_inst_file("../C/Instructions/Immediate", chunked[1], 'I', inst_count);
	char* op_name = to_upper(chunked[1]);
	char space[strlen(op_name) + 1];
	make_space(space, strlen(op_name) + 1);
	int op = htoi(chunked[3]);

	fprintf(output, "case I_%s:\n\tadd_instruction(new_i_inst(%s, %s, %s, %s, %s));\n\tbreak;\n", 
		op_name, chunked[3], chunked[4], chunked[5], chunked[6], chunked[7]);
	fprintf(i_types, "#define I_%s%s%d\n", 
		op_name, space, inst_count);
	fprintf(opcodes, "#define I_%s_OP_1%s%d\n", 
		op_name, space, op);
	int strval, n = 2;
	for(int i = 4; i < 6; i++) {
		if((strval = atoi(chunked[i])) != 0)
			fprintf(opcodes, "#define I_%s_OP_%d%s%d\n", op_name, n++, space, strval);

	}
}

void print_p_instruction(char** chunked, int inst_count, FILE* output, FILE* i_types, FILE* opcodes) {
	char* op_name = to_upper(chunked[1]);
	char space[strlen(op_name) + 1];
	make_space(space, strlen(op_name) + 1);

	fprintf(output, "case I_%s:\n\n\tbreak;\n", op_name);
	fprintf(i_types, "#define I_%s%s%d\n", op_name, space, inst_count);
}

void handle(char** chunked, int i, int* r_code_list, FILE* output, FILE* i_types, FILE* opcodes, FILE* r_codes, FILE* yacc) {
	print_yacc(chunked, yacc);
	switch(*(chunked[2])) {
		case 'R':
			print_r_instruction(chunked, i, r_code_list, output, i_types, opcodes, r_codes);
			break;
		case 'I':
			print_i_instruction(chunked, i, output, i_types, opcodes);
			break;
		case 'J':
			print_j_instruction(chunked, i, output, i_types, opcodes);
			break;
		case 'M':
			print_m_instruction(chunked, i, output, i_types, opcodes);
			break;
		case 'P':
			print_p_instruction(chunked, i, output, i_types, opcodes);
			break;
	}
}

void read_file(FILE* input, FILE* output, FILE* i_types, FILE* opcodes, FILE* r_codes, FILE* yacc) {
	char* line = malloc(BUFFER_SZ);
	int i = 0;
	int* r_code_list = (int*)malloc(sizeof(int)*32);
	memset(r_code_list, 0, sizeof(int)*32);
	fprintf(r_codes, "1: %d\n", 0);
	while(read_line(input, line)) {
		if(strlen(line) == 0 || line[0] == '#') continue;
		char** chunked = line_to_array(line);
		handle(chunked, i++, r_code_list, output, i_types, opcodes, r_codes, yacc);
		free_array(chunked);
	}
	free(line);
	free(r_code_list);
}

int main() {
	FILE* r_codes = fopen(H_R_CODES, "w+");
	check_file(r_codes, 1);
	FILE* opcodes = fopen(H_OPCODES, "w+");
	check_file(opcodes, 2);
	FILE* i_types = fopen(H_I_TYPES, "w+");
	check_file(i_types, 3);
	FILE* output = fopen(C_OUTPUT, "w+");
	check_file(output, 4);
	FILE* input = fopen(INPUT, "r");
	check_file(input, 5);
	FILE* yacc = fopen(Y_OUTPUT, "w+");
	check_file(yacc, 6);
	read_file(input, output, i_types, opcodes, r_codes, yacc);
	fclose(r_codes);
	fclose(opcodes);
	fclose(i_types);
	fclose(output);
	fclose(input);
	fclose(yacc);
	return 0;
}