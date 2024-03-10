#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#include "../include/Lista_Cidades.h"
#include "../include/Cidades.h"

typedef struct Lista_Caminhos{
    int parametro_k;
    int tamanho_da_lista;
    int *caminhos_possiveis;

} Lista_Caminhos;

Lista_Caminhos* criar_Lista_Caminhos(int parametro_k);
bool calcular_Caminhos_Possiveis(Lista_Caminhos *lista_caminhos, Lista_de_Cidades *lista_cidades);
int proxima_cidade(bool *cidades_visitadas, int *menores_caminhos, Lista_de_Cidades *lista_cidades);
void desalocar_Lista_Caminhos(Lista_Caminhos *lista_caminhos);

#endif