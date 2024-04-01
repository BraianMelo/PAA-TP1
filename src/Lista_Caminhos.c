#include "../include/Lista_Caminhos.h"

Lista_Caminhos* criar_Lista_Caminhos(int k){
    Lista_Caminhos *lista_caminhos = (Lista_Caminhos*) malloc(sizeof(Lista_Caminhos));
    lista_caminhos->k = k;
    lista_caminhos->qtd_caminhos = 0;

    lista_caminhos->Caminhos = (Caminho*) malloc(sizeof(Caminho) * k);

    for(int i = 0; i < lista_caminhos->k; ++i){
        iniciar_Caminho(&lista_caminhos->Caminhos[i]);
    }

    return lista_caminhos; 
}

bool adicionar_Caminho_na_Lista(Lista_Caminhos *lista_caminhos, int valor_do_caminho, int *cidade_anteriores, int tamanho){
    if(lista_caminhos->qtd_caminhos >= lista_caminhos->k - 1){
        if(lista_caminhos->qtd_caminhos > 0 && valor_do_caminho > lista_caminhos->Caminhos[lista_caminhos->qtd_caminhos - 1].valor)
            return false;
    }

    lista_caminhos->Caminhos[lista_caminhos->qtd_caminhos].valor = valor_do_caminho;
        
    int posicao = tamanho;

    while(posicao != 0){
        empilhar_aresta_no_caminho(&lista_caminhos->Caminhos[lista_caminhos->qtd_caminhos], posicao);
        posicao = cidade_anteriores[posicao];
    }

    empilhar_aresta_no_caminho(&lista_caminhos->Caminhos[lista_caminhos->qtd_caminhos], 0);
    lista_caminhos->qtd_caminhos++;

    Insertion_Sort(lista_caminhos->Caminhos, lista_caminhos->qtd_caminhos);
    return true;
}

void Insertion_Sort(Caminho *caminhos, int n) {
    for (int i = 1; i < n; i++) {
        Caminho chave = caminhos[i];
        int j = i - 1;

        while (j >= 0 && caminhos[j].valor > chave.valor) {
            caminhos[j + 1] = caminhos[j];
            j = j - 1;
        }
        caminhos[j + 1] = chave;
    }
}

void printar_Caminhos(Lista_Caminhos *lista_caminhos){
    for(int i = 0; i < lista_caminhos->qtd_caminhos; ++i){
        printar_Caminho(&lista_caminhos->Caminhos[i]);
    }
}

void desalocar_Lista_Caminhos(Lista_Caminhos *lista_caminhos){
    if(lista_caminhos == NULL)
        return;

    for(int i = 0; i < lista_caminhos->k; ++i){
        desalocar_Caminho(&lista_caminhos->Caminhos[i]);
    }
    
    free(lista_caminhos->Caminhos);
    free(lista_caminhos);
}

