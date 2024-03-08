#include "../include/Cidades.h"

Lista_de_Cidades* criar_Lista_de_cidades(int qtd_de_cidades) {
    Lista_de_Cidades *lc = (Lista_de_Cidades*) malloc(sizeof(Lista_de_Cidades));

    if (lc == NULL)
        return NULL;

    lc->qtd_de_cidades = qtd_de_cidades;
    lc->cidades = (Cidade*) malloc(sizeof(Cidade) * qtd_de_cidades);

    if (lc->cidades == NULL) {
        free(lc);
        return NULL;
    }

    for (int i = 0; i < qtd_de_cidades; ++i) {
        lc->cidades[i].id_cidade = i+1;
        lc->cidades[i].ini_vizinhanca = NULL;
        lc->cidades[i].fim_vizinhanca = NULL;
    }

    return lc;
}

void printar_Lista_de_Cidades(Lista_de_Cidades* lc) {
    if (lc == NULL || lc->qtd_de_cidades == 0) {
        printf("Lista de cidades nao existe.\n");
        return;
    }

    printf("Lista de Cidades:\n");
    for (int i = 0; i < lc->qtd_de_cidades - 1; ++i) {
        printf("Cidade %d, ", lc->cidades[i].id_cidade);
    }

    printf("Cidade %d\n", lc->cidades[lc->qtd_de_cidades - 1].id_cidade);

}

bool desalocar_Lista_de_Cidades(Lista_de_Cidades *lc) {
    if (lc == NULL)
        return false;

    for (int i = 0; i < lc->qtd_de_cidades; ++i) {
        desalocar_Cidade(&lc->cidades[i]);
    }

    free(lc->cidades);
    free(lc);
    return true;
}