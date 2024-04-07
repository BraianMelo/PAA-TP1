#include "../include/Dijkstra.h"

bool Dijkstra_Modificado(Lista_de_Cidades *lista_cidades, int k, FILE *arquivo_de_saida) {

    int *vezes_visitado = (int*) malloc(sizeof(int) * lista_cidades->qtd_de_cidades);
    Vizinhanca *vizinhanca;

    for(int i = 0; i < lista_cidades->qtd_de_cidades; ++i){
        vezes_visitado[i] = 0;
    }

    Heap_Prioridade *heap = criar_Heap_Prioridade(lista_cidades->qtd_de_cidades);

    inserir_Heap_Prioridade(heap, 0, 0);

    while (vezes_visitado[lista_cidades->qtd_de_cidades - 1] < k) {

        NO no = retirar_primeiro_elemento(heap);

        if(vezes_visitado[no.id_cidade] == k)
            continue;

        vezes_visitado[no.id_cidade] += 1;
        
        if(no.id_cidade == lista_cidades->qtd_de_cidades - 1)
            fprintf(arquivo_de_saida, "%ld ", no.prioridade);

        vizinhanca = lista_cidades->cidades[no.id_cidade].ini_vizinhanca;

        while(vizinhanca){
            inserir_Heap_Prioridade(heap, vizinhanca->id_cidade, (long int) vizinhanca->preco_viagem + no.prioridade);
            vizinhanca = vizinhanca->prox_cidade;
        }

    }

    liberar_Heap_Prioridade(heap);
    free(vezes_visitado);
    fprintf(arquivo_de_saida, "\n");
    return true;
}