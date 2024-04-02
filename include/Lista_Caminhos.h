#ifndef LISTA_CAMINHOS_H
#define LISTA_CAMINHOS_H

#include <stdio.h>
#include <malloc.h>

#include "../include/Caminho.h"

typedef struct Lista_Caminhos 
{
    int k;
    int qtd_caminhos;
    int tamanho;
    Caminho *Caminhos;

} Lista_Caminhos;

Lista_Caminhos* criar_Lista_Caminhos(int k);
bool adicionar_Caminho_na_Lista(Lista_Caminhos *lista_caminhos, int valor_do_caminho, int *cidade_anteriores, int tamanho);
void Insertion_Sort(Caminho *caminhos, int n);
void printar_Caminhos(Lista_Caminhos *lista_caminhos);
void desalocar_Lista_Caminhos(Lista_Caminhos *lista_caminhos);


#endif