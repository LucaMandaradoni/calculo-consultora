#include <stdio.h>
#include "../include/app.h"

void run_app(void) {
    int *ptr = NULL;

    printf("Antes del bug\n");

    *ptr = 10;   // 💥 BUG: dereferencia de NULL

    printf("Esto nunca se imprime\n");
}
