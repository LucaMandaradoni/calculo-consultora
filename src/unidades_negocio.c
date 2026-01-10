#include "app.h"
#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"



List* parsear_unidades_de_negocio(const char* json_text) {
    cJSON* root = cJSON_Parse(json_text);
    if (!root || !cJSON_IsObject(root))
        return NULL;

    List* unidades = list_create();

    cJSON* item = NULL;
    cJSON_ArrayForEach(item, root) {

        if (!cJSON_IsArray(item))
            continue;

        t_unidad_de_negocio* unidad = malloc(sizeof(t_unidad_de_negocio));
        unidad->nombre = strdup(item->string);
        unidad->saldos_meses = list_create();

        cJSON* saldo = NULL;
        cJSON_ArrayForEach(saldo, item) {
            if (cJSON_IsNumber(saldo)) {
                double* valor = malloc(sizeof(double));
                *valor = saldo->valuedouble;

                list_append(unidad->saldos_meses, valor);
          
            }
        }

        list_append(unidades, unidad);
    }

    cJSON_Delete(root);
    return unidades;
}


void destruir_unidad_de_negocio(void* data) {
    t_unidad_de_negocio* u = data;

    free(u->nombre);
    list_destroy(u->saldos_meses, free);
    free(u);
}


void imprimir_lista_negocios(List* lista_negocios){
    Node* current = lista_negocios->head;
    while (current) {
        t_unidad_de_negocio* unidad = (t_unidad_de_negocio*)current->data;
        printf("Unidad: %s\n", unidad->nombre);
        
        
        while(list_size(unidad->saldos_meses) > 0){
            
            double* puntero_al_numero = (double*)list_pop(unidad->saldos_meses);
            
            if (puntero_al_numero != NULL) {
                
                printf("%2.f\n", *puntero_al_numero);
                
        
                free(puntero_al_numero); 
            }
        }

        current = current->next;
    }
}


double sum_lista_negocios_por_mes(List* lista_negocios, int mes){

    t_unidad_de_negocio* unidad = malloc(sizeof(t_unidad_de_negocio));
    Node* current = lista_negocios -> head;
    
    double sumatoria = 0;

    mes -= 1;

    while(current){
        
        t_unidad_de_negocio* unidad = (t_unidad_de_negocio*)current->data;

        double* elemento_a_sumar = (double*)list_get(unidad->saldos_meses, mes);

        if(elemento_a_sumar != NULL){
            printf("elem suma %2.f\n", elemento_a_sumar);
            sumatoria += *elemento_a_sumar;
        }


        current = current->next;
    }
    printf("SE SUMO %2.f EN EL MES %d\n ", sumatoria, mes+1);
    return sumatoria;
}


double sum_lista_negocios_por_unidad(List* lista_negocios){
    if (!lista_negocios) return 0;
    
    Node* current = lista_negocios->head;
    t_unidad_de_negocio* unidad = (t_unidad_de_negocio*)current->data;

    unidad->saldos_meses;
    int cant_meses = list_size(unidad->saldos_meses);

    
    double sumatoria = list_sum(unidad->saldos_meses);

    printf("La unidad de negocio gano %2.f este anio\n", sumatoria);
    return sumatoria;

}