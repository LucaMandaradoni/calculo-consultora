#include "../include/app.h"
//#include <stdio.h>

int main(int argc, char* argv[]) {

    if(argc != 2){
        printf("Error, se detecto un numero diferente de 1 argumentos al iniciar master.");
    }


    char* parametro1 = argv[1];
    printf("el usuario ingreso %s \n", parametro1);


    run_app();
    return 0;
}
