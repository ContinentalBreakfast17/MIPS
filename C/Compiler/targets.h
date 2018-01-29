#define T_INST 0
#define T_DATA 1

typedef struct mips_target {
	char* 	name;
	int 	location;
} Target;

void init_target_list();
void new_target(char* name, int location, int type);
int get_target(char* name);