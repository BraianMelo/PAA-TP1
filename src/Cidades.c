#include "../include/Cidades.h"

Lista_de_Cidades* criar_Lista_de_cidades(int tamanho) {

    Lista_de_Cidades *lc = (Lista_de_Cidades*) malloc(sizeof(Lista_de_Cidades));

    lc->tamanho = tamanho;
    lc->id_cidades = (int*) malloc(sizeof(int) * tamanho);

    printf("Correto\n");
    return lc;
}

void printar_Lista_de_Cidades(Lista_de_Cidades* lc){
    for(int i = 0; i < lc->tamanho; ++i){
        printf("%d ", i);
    }
}

bool desalocar_Lista_de_Cidades(Lista_de_Cidades *lc){
    if(lc == NULL)
        return false;

    free(lc->id_cidades);
    free(lc);
    return true;
}