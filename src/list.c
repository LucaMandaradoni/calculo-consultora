#include <stdlib.h>
#include "list.h"




List* crear_lista(){
    List* lista_creada = malloc(sizeof(List));
    lista_creada -> head = NULL;
    return lista_creada;
}


void lista_push(List* lista, void *elemento){

        Node *node = malloc(sizeof(Node));
        node->data = elemento;
        node->next = lista->head;
        lista -> head = node;
}


void list_destroy(List *list, void (*free_fn)(void *)) {
    Node *current = list->head;
    while (current) {
        Node *next = current->next;
        if (free_fn)
            free_fn(current->data);
        free(current);
        current = next;
    }
    free(list);
}


void* list_get(List* list, int index){
    if(!list || index < 0)
        return NULL;

    Node *current = list->head;
    int cont = 0;

    while(current){
        
        if(cont == index){
            return current->data;
        }

        current = current->next;
        cont += 1;
    }
    return NULL;

}


int list_size(List* list){
    Node *current = list->head;
    int size = 0;

    while(current){

        current = current -> next;
        size += 1;

    }
    return size;
}



