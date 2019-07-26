#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "klist.h"

struct node* init_list(void *val, size_t val_size)
{
    struct node *list = (struct node*)malloc(sizeof(struct node));
    void *tmp_val = (void*)malloc(val_size);
    memcpy(tmp_val, val, val_size);
    list->data = tmp_val;
    list->next = NULL;

    return list;
}

void* list_element_at(struct node *list, int index)
{
    if (index < 0)
        return NULL;

    int size_of_list = list_size(&list);

    if (index >= size_of_list)
        return NULL;

    struct node *tmp = NULL;
    for (int i = 0; i <= index; ++i) {
        tmp = list;
        list = list->next;

        if (i == index)
            return tmp->data;
    }

    return NULL;
}

int is_list_init(struct node **list)
{
    if (*list == NULL)
        return 1;
    else
        return 0;
}
int list_size(struct node **list)
{
    int count = 0;
    struct node *tmp = *list;

    struct node *in_tmp = NULL;

    while (tmp != NULL || tmp->next != NULL) {
        in_tmp = tmp;
        tmp = tmp->next;

        ++count;

        if (tmp == NULL)
            break;
    }

    return count;
}

void insert_at_begin(struct node **list, void *val, size_t val_size)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    void *tmp_val = (void*)malloc(val_size);
    memcpy(tmp_val, val, val_size);

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
void insert_at_end(struct node **list, void *val, size_t val_size)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    void *tmp_val = (void*)malloc(val_size);
    memcpy(tmp_val, val, val_size);

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

    if (l == NULL)
        return;

    do {
        t = l;
        l = l->next;
        free(t);
        t = NULL;

        if (l == NULL)
            return;
    }
    while (l->next != NULL);
    
}
void traverse(struct node *list, void (*print_val)(struct node*))
{
    if (list == NULL)
        return;

    struct node *tmp;

    do {
        (*print_val)(list);
        tmp = list;
        list = list->next;
    }
    while(tmp->next != NULL);
}
