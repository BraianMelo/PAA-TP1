#include "../include/Heap_Prioridade.h"

Heap_Prioridade *criar_Heap_Prioridade(int capacidade) {
    Heap_Prioridade *heap = (Heap_Prioridade *)malloc(sizeof(Heap_Prioridade));
    heap->capacidade = capacidade;
    heap->tamanho = 0;
    heap->elementos = (NO *)malloc(capacidade * sizeof(NO));
    return heap;
}

void redimensionar(Heap_Prioridade *heap) {
    heap->capacidade *= 2;
    heap->elementos = realloc(heap->elementos, heap->capacidade * sizeof(NO));
}

void inserir_Heap_Prioridade(Heap_Prioridade *heap, int id_cidade, long int prioridade) {
    if (heap->tamanho == heap->capacidade)
        redimensionar(heap);

    int indice = heap->tamanho;
    heap->elementos[indice].id_cidade = id_cidade;
    heap->elementos[indice].prioridade = prioridade;
    heap->tamanho++;
    ajustarParaCima(heap, indice);
}

bool Heap_Prioridade_estah_vazia(Heap_Prioridade *heap) {
    return heap->tamanho == 0;
}

void liberar_Heap_Prioridade(Heap_Prioridade *heap) {
    free(heap->elementos);
    free(heap);
}

void ajustarParaCima(Heap_Prioridade *heap, int indice) {
    while (indice > 0 && heap->elementos[pai(indice)].prioridade > heap->elementos[indice].prioridade) {
        trocar(&heap->elementos[indice], &heap->elementos[pai(indice)]);
        indice = pai(indice);
    }
}

void ajustarParaBaixo(Heap_Prioridade *heap, int indice) {
    int menor = indice;
    int esquerdo = filhoEsquerdo(indice);
    int direito = filhoDireito(indice);

    if (esquerdo < heap->tamanho && heap->elementos[esquerdo].prioridade < heap->elementos[menor].prioridade)
        menor = esquerdo;

    if (direito < heap->tamanho && heap->elementos[direito].prioridade < heap->elementos[menor].prioridade)
        menor = direito;

    if (menor != indice) {
        trocar(&heap->elementos[indice], &heap->elementos[menor]);
        ajustarParaBaixo(heap, menor);
    }
}

NO retirar_primeiro_elemento(Heap_Prioridade *heap) {
    if (Heap_Prioridade_estah_vazia(heap)) {
        NO vazio = { -1, -1 };
        return vazio;
    }

    NO primeiro_elemento = heap->elementos[0];
    heap->tamanho--;

    if (heap->tamanho > 0) {
        heap->elementos[0] = heap->elementos[heap->tamanho];
        ajustarParaBaixo(heap, 0);
    }

    return primeiro_elemento;
}

bool elemento_na_heap(Heap_Prioridade *heap, int id_cidade) {
    for (int i = 0; i < heap->tamanho; i++) {
        if (heap->elementos[i].id_cidade == id_cidade) {
            return true;
        }
    }
    return false;
}

int pai(int i) {
    return (i - 1) / 2;
}

int filhoEsquerdo(int i) {
    return (2 * i) + 1;
}

int filhoDireito(int i) {
    return (2 * i) + 2;
}

void trocar(NO *a, NO *b) {
    NO temp = *a;
    *a = *b;
    *b = temp;
}

void printar_Heap(Heap_Prioridade *heap) {
    if (Heap_Prioridade_estah_vazia(heap)) {
        printf("A heap está vazia.\n");
        return;
    }

    printf("Elementos da Heap:\n");
    for (int i = 0; i < heap->tamanho; i++) {
        printf("(%d, %ld) ", heap->elementos[i].id_cidade, heap->elementos[i].prioridade);
    }
    printf("\n");
}
