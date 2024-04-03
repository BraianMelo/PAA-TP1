#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>


#include "../include/Cidade.h"
#include "../include/Lista_Cidades.h"

#include "../include/Caminho.h"
#include "../include/Lista_Caminhos.h"

#include "../include/Dijkstra.h"
#include "../include/Yen.h"

bool entrada_estah_correta(int n, int m, int k);

void start_timer(struct timeval *timer) {
    gettimeofday(timer, NULL);
}

double stop_timer(struct timeval *start) {
    struct timeval end;
    gettimeofday(&end, NULL);
    return (double)(end.tv_sec - start->tv_sec) + (double)(end.tv_usec - start->tv_usec) / 1000000.0;
}

int main() {
    struct timeval start_time;
    start_timer(&start_time);

    int n, m, k, a, b, c;

    scanf("%d %d %d", &n, &m, &k);

    if(!entrada_estah_correta(n, m, k)){
        printf("A entrada não atende os requisitos! \n");
        return 1;
    }

    Lista_de_Cidades *lista_cidades = criar_Lista_de_cidades(n);

    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        adicionar_Vizinho(&(lista_cidades->cidades[a-1]), b - 1, c);
        
    }

    Lista_Caminhos *lista_caminhos = criar_Lista_Caminhos(k);

    Yen(lista_caminhos, lista_cidades);

    desalocar_Lista_Caminhos(lista_caminhos);
    desalocar_Lista_de_Cidades(lista_cidades);

    double elapsed_time = stop_timer(&start_time);
    printf("Tempo decorrido: %.6f segundos\n", elapsed_time);

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("Tempo de CPU (s): %.6f\n", (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0);
    printf("Tempo de sistema (s): %.6f\n", (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0);

    return 0;
}

bool entrada_estah_correta(int n, int m, int k){
    if(n < 2 || n > 100000)
        return false;

    if(m < 1 || m > 200000)
        return false;

    if(k < 1 || k > 10)
        return false;

    return true;
}