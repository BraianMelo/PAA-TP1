#include <stdio.h>
#include <stdbool.h>

#include "../include/Cidade.h"
#include "../include/Lista_Cidades.h"
#include "../include/Caminho.h"
#include "../include/Lista_Caminhos.h"
#include "../include/Dijkstra.h"

bool entrada_estah_correta(int n, int m, int k);

int main(){

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

    Dijkstras(lista_caminhos, lista_cidades);

    printar_Caminhos(lista_caminhos);

    desalocar_Lista_Caminhos(lista_caminhos);
    desalocar_Lista_de_Cidades(lista_cidades);

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