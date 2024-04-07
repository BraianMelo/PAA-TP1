
#include "../include/Cidade.h"

Cidade* criar_Cidade(int id_cidade) {
    Cidade *c = (Cidade*) malloc(sizeof(Cidade));
    if (c == NULL) 
        return NULL;
    
    c->id_cidade = id_cidade;
    c->fim_vizinhanca = c->ini_vizinhanca = NULL;
    return c;
}

bool adicionar_Vizinho(Cidade *c, int id_cidade, int preco_viagem) {
    if (c == NULL) 
        return false;
    
    Vizinhanca *v = (Vizinhanca*) malloc(sizeof(Vizinhanca));
    if (v == NULL)
        return false;
    
    v->id_cidade = id_cidade;
    v->preco_viagem = preco_viagem;
    v->prox_cidade = NULL;

    if (c->ini_vizinhanca == NULL) {
        c->ini_vizinhanca = v;
        c->fim_vizinhanca = v;
    } else {
        c->fim_vizinhanca->prox_cidade = v;
        c->fim_vizinhanca = v;
    }

    return true;
}

void desalocar_Cidade(Cidade *c) {
    if (c == NULL) {
        return;
    }

    if(c->ini_vizinhanca == NULL){
        return;
    }

    while (c->ini_vizinhanca != c->fim_vizinhanca) {
        Vizinhanca *cv_aux = c->ini_vizinhanca;
        c->ini_vizinhanca = c->ini_vizinhanca->prox_cidade;
        free(cv_aux);
    }

    free(c->ini_vizinhanca);
}
