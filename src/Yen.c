#include "../include/Yen.h"


void Yen(Lista_Caminhos *lista_caminhos, Lista_de_Cidades *lista_cidades){

    Dijkstras(lista_caminhos, lista_cidades);

    for(int i = 1; i < lista_caminhos->k; ++i){

        int id_cidade_inicial = desempilhar_aresta_no_caminho(&lista_caminhos->Caminhos[0]);
        int id_cidade_destino = topo_do_Caminho(&lista_caminhos->Caminhos[0]);

        desabilitar_Vizinho(lista_cidades, id_cidade_inicial, id_cidade_destino);

        Dijkstras(lista_caminhos, lista_cidades);

        habilitar_Vizinho(lista_cidades, id_cidade_inicial, id_cidade_destino);

    }

}