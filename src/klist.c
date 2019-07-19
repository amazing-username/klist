#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "klist.h"


void insert_at_begin(struct node **list, void *val)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    void *tmp_val = malloc(sizeof(val));
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
    void *tmp_val = malloc(sizeof(val));
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
void traverse(struct node **list)
{
    if (*list == NULL)
        return;

    struct node *tmp;

    do
    {
        printf("node value %d\n", *(int*)(*list)->data);
        tmp = *list;
        *list = (*list)->next;
    }
    while(tmp->next != NULL);
}
