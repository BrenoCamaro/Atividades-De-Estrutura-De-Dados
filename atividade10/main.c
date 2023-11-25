#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

int main() {
    // Criar a tabela hash
    char** tabela = inicializarTabelaHash();

    // Inserir valores na tabela
    inserirValor("Stanford", "Inicio", tabela);
    inserirValor("Harvard", "Meio", tabela);
    inserirValor("Yale", "Fim", tabela);
    inserirValor("Columbia", "Fim", tabela);
    inserirValor("MIT", "Meio", tabela);

    // Obter e imprimir valores da tabela
    char* valorStanford = obterValor("Stanford", tabela);
    if (valorStanford != NULL) 
    {
        printf("Valor associado a Stanford: %s\n", valorStanford);
    } else 
    {
        printf("Stanford nao encontrado na tabela.\n");
    }

    char* valorHarvard = obterValor("Harvard", tabela);
    if (valorHarvard != NULL) 
    {
        printf("Valor associado a Harvard: %s\n", valorHarvard);
    } else 
    {
        printf("Harvard nao encontrado na tabela.\n");
    }

    char* valorYale = obterValor("Yale", tabela);
    if (valorYale != NULL) 
    {
        printf("Valor associado a Yale: %s\n", valorYale);
    } else 
    {
        printf("Yale não encontrado na tabela.\n");
    }

    // Liberar a memória alocada
    for (int i = 0; i < TAM_TABELA; i++) 
    {
        free(tabela[i]);
    }
    free(tabela);

    return 0;
}
