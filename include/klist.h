#include "types.h"

struct node* init_list(void*, size_t);

int is_list_init(struct node**);

void insert_at_begin(struct node**, void*, size_t);
void insert_at_end(struct node**, void*, size_t);
void free_list(struct node**);
void traverse(struct node*, void (*)(struct node*));
