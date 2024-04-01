#include "../include/Caminho.h"

#define INFINITO -1

void iniciar_Caminho(Caminho *caminho){
    caminho->qtd_arestas = 0;
    caminho->valor = INFINITO;

    caminho->caminho_percorrido = (int*) malloc(sizeof(int) * TAMANHO_INICIAL);
    caminho->tamanho_max = TAMANHO_INICIAL;

}

bool empilhar_aresta_no_caminho(Caminho *caminho,int id_cidade){
    if(caminho == NULL)
        return false;
    
    if(caminho->qtd_arestas + 1 == caminho->tamanho_max){
        caminho->tamanho_max *= 2;
        caminho->caminho_percorrido = (int*) realloc(caminho->caminho_percorrido, sizeof(int) * caminho->tamanho_max);

        if(caminho->caminho_percorrido == NULL)
            return false;
    }

    caminho->caminho_percorrido[caminho->qtd_arestas++] = id_cidade;
    return true;
}

bool desempilhar_aresta_no_caminho(Caminho *caminho){
    if(caminho == NULL)
        return false;

    --caminho->qtd_arestas;
    return true;
}

bool printar_Caminho(Caminho *caminho){
    if(caminho == NULL)
        return false; 

    for(int i = 0; i < caminho->qtd_arestas; ++i){
        printf("%d ", caminho->caminho_percorrido[i]);
    }
    printf("- valor = %d \n", caminho->valor);
    return true;
}


void desalocar_Caminho(Caminho *caminho){
    if(caminho == NULL)
        return;

    free(caminho->caminho_percorrido);
}