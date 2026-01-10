#include <stdio.h>
#include <stdlib.h> 
#include "list.h"
#include <string.h>
#include "cJSON.h"

#ifndef APP_H
#define APP_H

#define ENERO       1
#define FEBRERO     2
#define MARZO       3
#define ABRIL       4
#define MAYO        5
#define JUNIO       6
#define JULIO       7
#define AGOSTO      8
#define SEPTIEMBRE  9
#define OCTUBRE     10
#define NOVIEMBRE   11
#define DICIEMBRE   12

//List* meses = [ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE];

typedef struct{
    char* nombre;       //ej dentista
    List* saldos_meses; //ej [100,200,300,400,500,600,700,800,900,1000,1100,1200]
}t_unidad_de_negocio;

void run_app(void);


List* parsear_unidades_de_negocio(const char* json_string);
void destruir_unidad_de_negocio(void* unidad);
void imprimir_lista_negocios(List* lista_negocios);
double sum_lista_negocios_por_mes(List* lista_negocios, int mes);

#endif
