#include "../include/Yen.h"


void Yen(Lista_Caminhos *lista_caminhos, Lista_de_Cidades *lista_cidades){

    Dijkstras(lista_caminhos, lista_cidades);

    int posicao_caminho = 0;

    for(int i = 1; i < lista_caminhos->k; ++i){

        int id_cidade_inicial = desempilhar_aresta_no_caminho(&lista_caminhos->Caminhos[posicao_caminho]);

        if(id_cidade_inicial == lista_cidades->qtd_de_cidades-1){
            ++posicao_caminho;
            id_cidade_inicial = desempilhar_aresta_no_caminho(&lista_caminhos->Caminhos[posicao_caminho]);
        }

        int id_cidade_destino = topo_do_Caminho(&lista_caminhos->Caminhos[posicao_caminho]);

        desabilitar_Vizinho(lista_cidades, id_cidade_inicial, id_cidade_destino);

        Dijkstras(lista_caminhos, lista_cidades);

        habilitar_Vizinho(lista_cidades, id_cidade_inicial, id_cidade_destino);

    }

    Insertion_Sort(lista_caminhos->Caminhos, lista_caminhos->k);
    printar_Caminhos(lista_caminhos);

}