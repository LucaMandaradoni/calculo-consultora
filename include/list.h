#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
}Node;



typedef struct {
    Node *head;
}List;



List* list_create();
void list_push(List* lista, void *elemento);
void* list_pop(List* lista);
void list_destroy(List *list, void (*free_fn)(void *));
void* list_get(List* list, int index);
int list_size(List* list);
void list_append(List* lista, void *elemento);
double list_sum(List* list);

#endif 

