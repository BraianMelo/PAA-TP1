#ifndef CIDADE_H

    #define CIDADE_H

    #include <stdio.h>
    #include <malloc.h>
    #include <stdbool.h>

    typedef struct Vizinhanca{
        int id_cidade;
        int preco_viagem;
        struct Vizinhanca *prox_cidade;
    } Vizinhanca; //No

    typedef struct Cidade{
        int id_cidade;
        Vizinhanca *ini_vizinhanca;
        Vizinhanca *fim_vizinhanca;
    } Cidade; //Cabecalho

    //Uma lista encadeada

    Cidade *criar_Cidade(int id_cidade);
    bool adicionar_Vizinho(Cidade *c,int id_cidade, int preco_viagem);
    void desalocar_Cidade(Cidade *c);

#endif
