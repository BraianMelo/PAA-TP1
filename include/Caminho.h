#ifndef CAMINHO_H
#define CAMINHO_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#include "../include/Cidade.h"

#define TAMANHO_INICIAL 10

typedef struct Caminho
{
    int valor;
    int *caminho_percorrido;
    int qtd_arestas;
    int tamanho_max;
    
} Caminho;

void iniciar_Caminho(Caminho *caminho);
bool empilhar_aresta_no_caminho(Caminho *caminho,int id_cidade);
int desempilhar_aresta_no_caminho(Caminho *caminho);
int topo_do_Caminho(Caminho *caminho);
bool printar_Caminho(Caminho *caminho);
void desalocar_Caminho(Caminho *caminho);

#endif