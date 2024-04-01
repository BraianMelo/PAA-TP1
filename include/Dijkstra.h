#ifndef DIJKSTRA_H

    #define DIJKSTRA_H

    #include <stdio.h>
    #include <malloc.h>
    #include <stdbool.h>

    #include "../include/Cidade.h"
    #include "../include/Lista_Cidades.h"
    #include "../include/Caminho.h"
    #include "../include/Lista_Caminhos.h"

    #define INFINITO -1

    Lista_Caminhos* criar_Lista_Caminhos(int parametro_k);
    bool Dijkstras(Lista_Caminhos *lista_caminhos, Lista_de_Cidades *lista_cidades);
    int proxima_cidade(Lista_de_Cidades *lista_cidades, bool *cidades_visitadas, int *menores_caminhos);

#endif