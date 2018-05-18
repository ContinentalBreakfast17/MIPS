typedef struct reorder_buffer_slot {
	unsigned int 	dest;
	Data 			value;
	char 			type;
	char 			exception;
	char 			ready;
} Buffer_Entry;

typedef struct reorder_buffer {
	Buffer_Entry** 	queue;
	int 			capacity;
	int 			front;
	int 			count;
} Reorder_Buffer;

Reorder_Buffer* 	init_reorder_buffer(int capacity);
int 				is_full(Reorder_Buffer* buffer);
Buffer_Entry*		new_buffer_entry();
void 				commit_front(Reorder_Buffer* buffer);
void 				mark_ready(Buffer_Entry* entry);