#include "../include/app.h"
//#include <stdio.h>

int main(int argc, char* argv[]) {

    //printf("a\n");
    if(argc != 3 || (atoi(argv[1]) <= 0)){
        
        printf("Error, se detecto un numero diferente de 3 argumentos. \n");
        
        return 0;
    }

    char* cant_unidades_de_negocio = atoi(argv[1]);
    char* parametro2 = argv[2];
    char* parametro3 = argv[3];

    //ingresar unidades de negocios una a una?

    printf("el usuario ingreso %s \n", cant_unidades_de_negocio);
    printf("el usuario ingreso %s \n", parametro2);
    printf("el usuario ingreso %s \n", parametro3);


    //run_app();
    return 0;
}
