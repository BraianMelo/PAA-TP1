#ifndef DIJKSTRA_H

    #define DIJKSTRA_H

    #include <stdio.h>

    #include "../include/Lista_Cidades.h"
    #include "../include/Heap_Prioridade.h"

    #define INFINITO -1

    bool Dijkstra_Modificado(Lista_de_Cidades *lista_cidades, int k, FILE *caminho_arq_saida);

#endif