 #include "../include/Dijkstra.h"

Lista_Caminhos* criar_Lista_Caminhos(int parametro_k){
    Lista_Caminhos *lista_caminhos = (Lista_Caminhos*) malloc(sizeof(Lista_Caminhos));
    lista_caminhos->parametro_k = parametro_k;
    lista_caminhos->tamanho_da_lista = 0;

    int *caminhos_possiveis = (int*) malloc(sizeof(int));
    lista_caminhos->caminhos_possiveis = caminhos_possiveis;

    return lista_caminhos;
}

bool calcular_Caminhos_Possiveis(Lista_Caminhos *lista_caminhos, Lista_de_Cidades *lista_cidades){
    bool *cidades_visitadas = (bool*) malloc(sizeof(bool) * lista_cidades->qtd_de_cidades);
    int *menores_caminhos = (int*) malloc(sizeof(int) * lista_cidades->qtd_de_cidades);
    int id_cidade = 0;

    cidades_visitadas[0] = true;
    menores_caminhos[0] = 0;

    for(int i = 1; i < lista_cidades->qtd_de_cidades; ++i){
        cidades_visitadas[i] = false;
        menores_caminhos[i] = -1;
    }

    int cidade_atual = 0;

    while(cidade_atual != -1){
        cidades_visitadas[cidade_atual] = true;

        printf("Cidade %d \n", cidade_atual);

        Vizinhanca *vizinhanca = lista_cidades->cidades[cidade_atual].ini_vizinhanca;

        while(vizinhanca != NULL){
            if(vizinhanca->id_cidade == lista_cidades->qtd_de_cidades - 1)
                printf("Valor: %d \n", vizinhanca->preco_viagem + menores_caminhos[cidade_atual]);

            if(menores_caminhos[vizinhanca->id_cidade] == -1){
                menores_caminhos[vizinhanca->id_cidade] = vizinhanca->preco_viagem + menores_caminhos[cidade_atual];
           
            } else {
                if(menores_caminhos[vizinhanca->id_cidade] > vizinhanca->preco_viagem + menores_caminhos[cidade_atual]){
                    menores_caminhos[vizinhanca->id_cidade] = vizinhanca->preco_viagem + menores_caminhos[cidade_atual];
                    cidades_visitadas[vizinhanca->id_cidade] = false;
                }
            }
           
            vizinhanca = vizinhanca->prox_cidade;
        }

        printf("Menores caminhos: ");
        for(int i = 0; i < lista_cidades->qtd_de_cidades; ++i){
            printf("%d ", menores_caminhos[i]);
        }
        printf("\n");
        

        cidade_atual = proxima_cidade(cidades_visitadas, menores_caminhos, lista_cidades);
    }


    printf("Menores caminhos: ");
    for(int i = 0; i < lista_cidades->qtd_de_cidades; ++i){
        printf("%d ", menores_caminhos[i]);
    }
    printf("\n");


    free(cidades_visitadas);
    free(menores_caminhos);
    return true;
}

int proxima_cidade(bool *cidades_visitadas, int *menores_caminhos, Lista_de_Cidades *lista_cidades){
    int proxima_cidade = -1;
    int menor_caminho = -1;
    
    for(int i = 0; i < lista_cidades->qtd_de_cidades; ++i){
        if(!cidades_visitadas[i] && menores_caminhos[i] != -1){
            if(menores_caminhos[i] < menor_caminho || menor_caminho == -1){
                proxima_cidade = i;
                menor_caminho = menores_caminhos[i];
            }
        }
    }

    return proxima_cidade;
}

void desalocar_Lista_Caminhos(Lista_Caminhos *lista_caminhos){
    if(lista_caminhos == NULL)
        return;

    free(lista_caminhos->caminhos_possiveis);
    free(lista_caminhos);
}