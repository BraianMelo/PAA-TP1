#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/Tempo.h"

#include "../include/Cidade.h"
#include "../include/Lista_Cidades.h"

#include "../include/Heap_Prioridade.h"
#include "../include/Dijkstra.h"

bool receber_argumentos(int argc, char *argv[], char **arquivo_de_entrada, char **arquivo_de_saida);
bool abrir_arquivos(FILE **arquivo_entrada, FILE **arquivo_saida, const char *arquivo_entrada_nome, const char *arquivo_saida_nome);
void fechar_arquivos(FILE *arquivo_entrada, FILE *arquivo_saida);

bool entrada_estah_correta(int n, int m, int k); //Checa se N, M e K esta no intervalo valido

int main(int argc, char *argv[]) {
    char *arquivo_de_entrada = NULL;
    char *arquivo_de_saida = NULL;

    if (!receber_argumentos(argc, argv, &arquivo_de_entrada, &arquivo_de_saida))
        return EXIT_FAILURE;

    FILE *arquivo_entrada, *arquivo_saida;

    if (!abrir_arquivos(&arquivo_entrada, &arquivo_saida, arquivo_de_entrada, arquivo_de_saida))
        return EXIT_FAILURE;

    struct timeval ini_tempo_total, fim_tempo_total;
    struct rusage inicio, fim;

    int n, m, k, a, b, c;

    if (fscanf(arquivo_entrada, "%d %d %d", &n, &m, &k) != 3) {
        fprintf(stderr, "Erro ao ler os valores\n");

        fechar_arquivos(arquivo_entrada, arquivo_saida);
        return EXIT_FAILURE;
    }

    if (!entrada_estah_correta(n, m, k)) {
        fprintf(stderr, "A entrada não atende os requisitos!\n");

        fechar_arquivos(arquivo_entrada, arquivo_saida);
        return EXIT_FAILURE;
    }

    Lista_de_Cidades *lista_cidades = criar_Lista_de_cidades(n);

    for (int i = 0; i < m; ++i) {
        if (fscanf(arquivo_entrada, "%d %d %d", &a, &b, &c) != 3) {
            fprintf(stderr, "Erro ao ler os vizinhos do arquivo de entrada.\n");

            fechar_arquivos(arquivo_entrada, arquivo_saida);
            desalocar_Lista_de_Cidades(lista_cidades);
            return EXIT_FAILURE;
        }

        adicionar_Vizinho(&(lista_cidades->cidades[a - 1]), b - 1, c);
    }

    iniciar_contagem(&ini_tempo_total, &inicio);

    Dijkstra_Modificado(lista_cidades, k, arquivo_saida);

    parar_contagem(&fim_tempo_total, &fim);

    desalocar_Lista_de_Cidades(lista_cidades);

    printar_tempo_gasto(&ini_tempo_total, &inicio, &fim_tempo_total, &fim, arquivo_saida);

    fechar_arquivos(arquivo_entrada, arquivo_saida);

    return EXIT_SUCCESS;
}

bool receber_argumentos(int argc, char *argv[], char **arquivo_de_entrada, char **arquivo_de_saida) {
    int opt;

    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
            case 'i':
                *arquivo_de_entrada = optarg;
                break;
            case 'o':
                *arquivo_de_saida = optarg;
                break;
            case '?':
                if (optopt == 'i' || optopt == 'o') {
                    fprintf(stderr, "Opção -%c requer um argumento.\n", optopt);
                } else {
                    fprintf(stderr, "Opção desconhecida '-%c'.\n", optopt);
                }
                return false;
            default:
                abort();
        }
    }

    if (*arquivo_de_entrada == NULL || *arquivo_de_saida == NULL) {
        fprintf(stderr, "Você deve fornecer tanto o arquivo de entrada (-i) quanto o arquivo de saída (-o).\n");
        return false;
    }

    return true;
}

bool abrir_arquivos(FILE **arquivo_entrada, FILE **arquivo_saida, const char *arquivo_entrada_nome, const char *arquivo_saida_nome) {
    *arquivo_entrada = fopen(arquivo_entrada_nome, "r");
    if (*arquivo_entrada == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de entrada '%s'\n", arquivo_entrada_nome);
        
        return false;
    }

    *arquivo_saida = fopen(arquivo_saida_nome, "w");
    if (*arquivo_saida == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de saída '%s'\n", arquivo_saida_nome);

        fclose(*arquivo_entrada);
        return false;
    }

    return true;
}

void fechar_arquivos(FILE *arquivo_entrada, FILE *arquivo_saida) {
    fclose(arquivo_entrada);
    fclose(arquivo_saida);
}

bool entrada_estah_correta(int n, int m, int k) {
    if (n < 2 || n > 100000)
        return false;

    if (m < 1 || m > 200000)
        return false;

    if (k < 1 || k > 10)
        return false;

    return true;
}
