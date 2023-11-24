#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lista.h"

int main(int argc, char* argv[]){

    FILE* f;                         /* Ponteiro para arquivo */
    No* lista_ordenada = NULL;       /* Lista encadeada ordenada */
    No* lista_nao_ordenada = NULL;   /* Lista encadeada não ordenada*/
    clock_t inicio, fim;             /* Variáveis para medir o tempo */
    float valor;
    double cpu_time_used;           /* Variável para armazenar tempo em segundos */
    char arq[100];

/* Verifica se um nome de arquivo foi fornecido como argumento de linha de comando */
    if(argc == 1)
    {
        strcpy(arq, "1kk_rand_float.csv");
    }
    else
    {
        strcpy(arq,"rand.csv");
    }

    /*  Abre o arquivo para leitura */

    f = fopen(arq, "r");

    if(f == NULL)
    {
        perror("Erro... Nao foi possive abrir o arquivo.");
        fclose(f); 
        exit(1);
    }

    inicio = clock(); /* Registra o tempo de inicio */

    while(fscanf(f,"%f\n",&valor) == 1)
    {
        if(lista_nao_ordenada == NULL)
        {
            lista_nao_ordenada = no(valor, NULL);
        }
        else
        {
            lista_inserir_no(lista_nao_ordenada, no(valor, NULL));
        }
        
    }

    fim = clock(); /* Registra o tempo de término */

    fclose(f);
    cpu_time_used = ((double) (fim - inicio)) / CLOCKS_PER_SEC; /*  Calcula o tempo em segundos */
    printf("\nTempo (s) carregamento lista nao ordenada: %.6fs", cpu_time_used);
    lista_liberar(lista_nao_ordenada);
    lista_nao_ordenada = NULL;

    /* Lista Ordenada */
    f = fopen(arq, "r");
    if(f == NULL)
    {
        perror("Erro... Nao foi possive abrir o arquivo.");
        fclose(f);
        exit(1);
    }

    inicio = clock();

    while(fscanf(f,"%f\n",&valor) == 1)
    {
        if(lista_ordenada == NULL)
        {
            lista_ordenada = no(valor, NULL);
        }
        else
        {
            lista_inserir_no_ordenado(&lista_ordenada, no(valor, NULL));
        }
        
    }

    fim = clock();

    fclose(f);
    cpu_time_used = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nTempo (s) carregamento lista ordenada: %.6fs", cpu_time_used);

    lista_liberar(lista_ordenada);
    lista_ordenada = NULL;

    exit(0);
}