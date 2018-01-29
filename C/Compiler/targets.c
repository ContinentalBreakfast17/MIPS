#define TABLE_SZ 257
#define HASH_Z 	 7

typedef struct target_list_node {
	Target*		target;
	Node* 		next;
} Node;

typedef struct target_linked_list {
	Node*		head;
	Node* 		tail;
} List;

typedef struct target_linked_hash_table {
	List** 		table;
	long long	capacity;
	int 		count;
} Table;

Node* new_node(Target* target) {
	Node* node = (Node*)malloc(sizeof(Node));
	check_alloc((void*)node);
	node->target = target;
	node->next = NULL;
	return node;
}

List* new_list() {
	List* list = (List*)malloc(sizeof(List));
	check_alloc((void*)list);
	list->head = NULL;
	list->tail = NULL;
	return list;
}

Table* target_table = NULL;

void init_target_list() {
	target_table = (Table*)malloc(sizeof(Table));
	check_alloc((void*)target_table);
	target_table->capacity = TABLE_SZ;
	target_table->count = 0;

	target_table->table = (List**)malloc(sizeof(List*)*TABLE_SZ);
	check_alloc((void*)target_table->table);

	int i;
	for(i = 0; i < TABLE_SZ; i++) {
		target_table->table[i] = new_list();
	}
}

int hash(char* name) {
	int i, n = strlen(name), result = (int)name[0];
	for(i = 1; i < n; i++) {
		result += result*HASH_Z + (int)name[i];
	}
	return result % target_table->capacity;
}

void resize_table() {
	long long cap = target_table->capacity*2+1;
	while(!is_prime(cap += 2));
	target_table->capacity = cap;
	target_table->table = (List**)realloc(target_table->table, sizeof(List*)*cap);
}

void add_node(Node* node) {
	char* name = node->target->name;
	if(get_target(name) >= 0) {
		printf("Error: target '%s' defined multiple times\n", name);
		exit(1);
	}

	List* list = target_table->table[hash(name)];
	if(list->head != NULL)
		list->tail = list->tail->next = node;
	list->head = list->tail = node;

	target_table->count++;
	if(target_table->count > target_table->capacity/2)
		resize_table();
}

void new_target(char* name, int location) {
	Target* target = (Target*)malloc(sizeof(Target));
	check_alloc((void*)target);
	target->name = name;
	target->location = location;
	add_node(new_node(target));
}

int get_target(char* name) {
	Node* node = target_table->table[hash]->head;
	char* node_name = node->target->name;
	while(node != NULL) {
		if(strcmp(node_name, name) == 0) return node->target->location;
		node = node->next;
	}
	return -1;
}