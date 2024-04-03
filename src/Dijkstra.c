#include "../include/Dijkstra.h"


bool Dijkstras(Lista_Caminhos *lista_caminhos, Lista_de_Cidades *lista_cidades) {
    bool *cidades_visitadas = (bool*) malloc(sizeof(bool) * lista_cidades->qtd_de_cidades);
    int *menores_caminhos = (int*) malloc(sizeof(int) * lista_cidades->qtd_de_cidades);
    int *cidades_anteriores = (int*) malloc(sizeof(int) * lista_cidades->qtd_de_cidades);

    int id_cidade = 0;
    cidades_visitadas[0] = true;
    menores_caminhos[0] = 0;
    cidades_anteriores[0] = 0;

    for(int i = 1; i < lista_cidades->qtd_de_cidades; ++i){
        cidades_visitadas[i] = false;
        menores_caminhos[i] = INFINITO;
        cidades_anteriores[i] = INFINITO;
    }

    int cidade_atual = 0;

    while(cidade_atual != INFINITO){
        cidades_visitadas[cidade_atual] = true;

        Vizinhanca *vizinhanca = lista_cidades->cidades[cidade_atual].ini_vizinhanca;

        while(vizinhanca != NULL){

            if(!vizinhanca->caminho_valido){
                vizinhanca = vizinhanca->prox_cidade;
                continue;
            }


            if(menores_caminhos[vizinhanca->id_cidade] == INFINITO){
                menores_caminhos[vizinhanca->id_cidade] = vizinhanca->preco_viagem + menores_caminhos[cidade_atual];
                cidades_anteriores[vizinhanca->id_cidade] = cidade_atual;

            } else {
                if(menores_caminhos[vizinhanca->id_cidade] > vizinhanca->preco_viagem + menores_caminhos[cidade_atual]){
                    menores_caminhos[vizinhanca->id_cidade] = vizinhanca->preco_viagem + menores_caminhos[cidade_atual];
                    cidades_anteriores[vizinhanca->id_cidade] = cidade_atual;
                }
            }

            vizinhanca = vizinhanca->prox_cidade;
        }

        cidade_atual = proxima_cidade(lista_cidades, cidades_visitadas, menores_caminhos);
    }

    adicionar_Caminho_na_Lista(lista_caminhos, menores_caminhos[lista_cidades->qtd_de_cidades - 1], cidades_anteriores, lista_cidades->qtd_de_cidades - 1);

    free(cidades_visitadas);
    free(menores_caminhos);
    free(cidades_anteriores);

    return true;
}

int proxima_cidade(Lista_de_Cidades *lista_cidades, bool *cidades_visitadas, int *menores_caminhos){
    int proxima_cidade = INFINITO;
    int menor_caminho = INFINITO;
    
    for(int i = 0; i < lista_cidades->qtd_de_cidades; ++i){
        if(!cidades_visitadas[i] && menores_caminhos[i] != INFINITO){
            if(menores_caminhos[i] < menor_caminho || menor_caminho == INFINITO){
                proxima_cidade = i;
                menor_caminho = menores_caminhos[i];
            }
        }
    }
    
    return proxima_cidade;
}
