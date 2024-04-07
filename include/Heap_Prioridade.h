#ifndef HEAP_PRIORIDADE_H
    
    #define HEAP_PRIORIDADE_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    typedef struct {
        int id_cidade;
        long int prioridade;
    } NO; //Elementos

    typedef struct {
        int capacidade;
        int tamanho;
        NO *elementos;
    } Heap_Prioridade; //Cabecalho

    Heap_Prioridade *criar_Heap_Prioridade(int capacidade);

    void inserir_Heap_Prioridade(Heap_Prioridade *heap, int id_cidade, long int prioridade);
    NO retirar_primeiro_elemento(Heap_Prioridade *heap);

    bool elemento_na_heap(Heap_Prioridade *heap, int id_cidade);
    bool Heap_Prioridade_estah_vazia(Heap_Prioridade *heap);

    void redimensionar(Heap_Prioridade *heap);
    void ajustarParaCima(Heap_Prioridade *heap, int indice);
    void ajustarParaBaixo(Heap_Prioridade *heap, int indice);

    int pai(int i);
    int filhoEsquerdo(int i);
    int filhoDireito(int i);
    void trocar(NO *a, NO *b);

    void printar_Heap(Heap_Prioridade *heap);

    void liberar_Heap_Prioridade(Heap_Prioridade *heap);

#endif
