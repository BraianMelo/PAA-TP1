#ifndef CIDADE_H

    #define CIDADE_H

    #include <stdio.h>
    #include <string.h>
    #include <malloc.h>
    #include <stdbool.h>

    #include "../include/Cidade.h"

    typedef struct Lista_de_Cidades{
        int qtd_de_cidades;
        Cidade* cidades;
    } Lista_de_Cidades;

    Lista_de_Cidades* criar_Lista_de_cidades(int qtd_de_cidades);
    void printar_Lista_de_Cidades(Lista_de_Cidades *lc);
    Cidade *achar_Cidade(Lista_de_Cidades *lc ,int id_cidade);
    bool desalocar_Lista_de_Cidades(Lista_de_Cidades *lc);

#endif