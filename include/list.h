#ifndef LIST_H
#define LIST_H


typedef struct Node {
    void *data;
    struct Node *next
} Node;



typedef struct {
    Node *head;
} List;



List* crear_lista();
void lista_push(List* lista, void *elemento);
void list_destroy(List *list, void (*free_fn)(void *));
void* list_get(List* list, int index);
int list_size(List* list);

#endif 

