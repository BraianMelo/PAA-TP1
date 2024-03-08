#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Lista_de_Cidades{
    int tamanho;
    int *id_cidades;
} Lista_de_Cidades;

Lista_de_Cidades* criar_Lista_de_cidades(int tamanho);
void printar_Lista_de_Cidades(Lista_de_Cidades *lc);
bool desalocar_Lista_de_Cidades(Lista_de_Cidades *lc);