#include "../include/app.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    // if(argc != 3 || (atoi(argv[1]) <= 0)){
        
    //     printf("Error, se detecto un numero diferente de 3 argumentos. \n");
        
    //     return 0;
    // }

    const char* json_recibido = "{\"medialunas\": [100,200,300,400,500,600,700,800,900,1000,1100,1200], \"cafe\": [100,200,300,400,500,600,700,800,900,1000,1100,1200], \"tortas\": [100,200,300,400,500,600,700,800,900,1000,1100,1200]}";
    printf("json recibido %s\n", json_recibido);
    


    List* lista_negocios = parsear_unidades_de_negocio(json_recibido);
    if (!lista_negocios) {
        printf("Error: no se pudo parsear el JSON\n");
        return 1;
    }
    printf("Se encontraron %d unidades de negocio.\n", list_size(lista_negocios));

    int mes = MAYO;

    //imprimir_lista_negocios(lista_negocios);

    sum_lista_negocios_por_mes(lista_negocios, mes);
    sum_lista_negocios_por_unidad(lista_negocios);



    list_destroy(lista_negocios, destruir_unidad_de_negocio);

    return 0;
}
