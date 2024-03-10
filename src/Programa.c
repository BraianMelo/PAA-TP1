#include <stdio.h>

#include "../include/Cidades.h"
#include "../include/Lista_Cidades.h"
#include "../include/Dijkstra.h"

int main(){

    int n, m, k, a, b, c;

    scanf("%d %d %d", &n, &m, &k);

    Lista_de_Cidades *lista_cidades = NULL;
    lista_cidades = criar_Lista_de_cidades(n);

    printar_Lista_de_Cidades(lista_cidades);

    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        adicionar_Vizinho(&(lista_cidades->cidades[a-1]), b - 1, c);
        
    }

    Lista_Caminhos *lista_caminhos = criar_Lista_Caminhos(k);
    calcular_Caminhos_Possiveis(lista_caminhos, lista_cidades);


    desalocar_Lista_Caminhos(lista_caminhos);
    desalocar_Lista_de_Cidades(lista_cidades);

    return 0;
}