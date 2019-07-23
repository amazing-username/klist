#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "klist.h"

struct node* init_list(void *val)
{
    struct node *list = (struct node*)malloc(sizeof(struct node));
    void *tmp_val = (void*)malloc(sizeof(val));
    memcpy(tmp_val, val, sizeof(val));
    list->data = tmp_val;
    list->next = NULL;

    return list;
}

int is_list_init(struct node **list)
{
    if (*list == NULL)
        return 1;
    else
        return 0;
}

void insert_at_begin(struct node **list, void *val)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    void *tmp_val = (void*)malloc(sizeof(val));
    memcpy(tmp_val, val, sizeof(val));

    if ((*list) == NULL) {
        (*list) = tmp;
        (*list)->data = tmp_val;
        (*list)->next = NULL;
        return;
    }

    tmp->data = tmp_val;
    tmp->next = *list;
    *list = tmp;
}
void insert_at_end(struct node **list, void *val)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    void *tmp_val = (void*)malloc(sizeof(val));
    memcpy(tmp_val, val, sizeof(val));

    if ((*list) == NULL) {
        (*list) = tmp;
        (*list)->data = tmp_val;
        (*list)->next = NULL;
        return;
    }

    tmp = *list;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = (struct node*)malloc(sizeof(struct node));
    tmp->next->data = tmp_val;
    tmp->next->next = NULL;
}
void free_list(struct node **list)
{
    struct node *t = NULL;
    struct node *l = *list;

    do {
        t = l;
        l = l->next;
        free(t);
        t = NULL;
    }
    while (l->next != NULL);
    
}
void traverse(struct node *list, void (*print_val)(struct node*))
{
    if (list == NULL)
        return;

    struct node *tmp;

    do
    {
        (*print_val)(list);
        tmp = list;
        list = list->next;
    }
    while(tmp->next != NULL);
}
