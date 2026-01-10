#include <stdlib.h>
#include "list.h"


List* list_create(){
    List* lista_creada = malloc(sizeof(List));
    lista_creada -> head = NULL;
    return lista_creada;
}


void list_push(List* lista, void *elemento){

        Node *node = malloc(sizeof(Node));
        if (node == NULL) return;

        node->data = elemento;
        node->next = lista->head;
        lista -> head = node;
}


void* list_pop(List* lista){
    if (!lista || !lista->head)
        return NULL;

    Node* nodo = lista->head;
    void* elemento = nodo->data;

    lista->head = nodo->next;
    free(nodo);

    return elemento;
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
    if (!list) return 0;
    
    Node *current = list->head;
    int size = 0;

    while(current){

        size += 1;
        current = current -> next;
    }
    return size;
}


void list_append(List* lista, void *elemento){
    Node* nuevo = malloc(sizeof(Node));
    nuevo->data = elemento;
    nuevo->next = NULL;

    if (!lista->head) {
        lista->head = nuevo;
        return;
    }

    Node* current = lista->head;
    while (current->next)
        current = current->next;

    current->next = nuevo;
}


double list_sum(List* list){


     if (list == NULL || list->head == NULL) return 0;
    double sumatoria = 0;
     
    Node* current = list->head;

    while(current){

        double* elemento_a_sumar = (double*) current->data;

        if(elemento_a_sumar !=NULL){
            sumatoria += *elemento_a_sumar;
        }

        current = current->next;
    }

    return sumatoria;

}
