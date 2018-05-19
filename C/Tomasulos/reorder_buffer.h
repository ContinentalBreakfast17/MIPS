#define ROB_DEFAULT	0
#define ROB_WR 		1
#define ROB_STORE	2
#define ROB_BRANCH 	4

typedef struct reorder_buffer_dest {
	unsigned int 	address;
	unsigned int 	reg: 			6;
	unsigned int	fp: 			2;
	unsigned int 	size:	 		4;
	unsigned int 	mem_alignment:	4;
} Buffer_Dest;

typedef struct reorder_buffer_slot {
	Buffer_Dest* 		dest;
	Data				value;
	char 				type;
	char 				exception;
	char 				ready;
} Buffer_Entry;

typedef struct reorder_buffer {
	Buffer_Entry** 	queue;
	int 			capacity;
	int 			front;
	int 			count;
} Reorder_Buffer;

Reorder_Buffer* 	init_reorder_buffer(int capacity);
int 				is_full(Reorder_Buffer* buffer);
Buffer_Entry*		add_buffer_entry();
void 				commit_front(Reorder_Buffer* buffer);
void 				mark_ready(Buffer_Entry* entry);