#include <stdio.h>

#include "../include/Cidades.h"
#include "../include/Lista_Cidades.h"

int main(){

    int n, m, k, a, b, c;

    scanf("%d %d %d", &n, &m, &k);

    Lista_de_Cidades *lc = NULL;
    lc = criar_Lista_de_cidades(n);

    printar_Lista_de_Cidades(lc);

    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        adicionar_Vizinho(&(lc->cidades[a-1]), b, c);
        
    }

    desalocar_Lista_de_Cidades(lc);

    return 0;
}