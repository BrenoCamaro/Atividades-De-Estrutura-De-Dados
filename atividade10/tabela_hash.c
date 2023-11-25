#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tabela_hash.h"

#define TAM_ALFABETO 26
#define TAM_TABELA 1000
#define TAM_VALOR 100

// Função para calcular o hash da chave
int calcularHash(char* chave) {
    // A fórmula de hash utiliza a posição das letras na tabela ASCII
    return ((toupper(chave[0]) - 65) * TAM_ALFABETO) + (toupper(chave[1]) - 65);
}

// Função para inicializar a tabela hash
char** inicializarTabelaHash() {
    // Alocar espaço para a tabela
    char** tabela = malloc(sizeof(char*) * TAM_TABELA);

    // Inicializar cada entrada na tabela
    for(int i = 0; i < TAM_TABELA; i++)
     {
        tabela[i] = malloc(sizeof(char) * TAM_VALOR);
        // Inicializar com uma string vazia
        strcpy(tabela[i], "");
    }

    return tabela;
}

// Função para inserir um valor na tabela hash
void inserirValor(char* chave, char* valor, char** tabela) {
    // Calcular o hash da chave e atribuir o valor à posição correspondente na tabela

    int posicao = calcularHash(chave);
    printf("Inserindo chave '%s' na posicao %d\n", chave, posicao);
    strcpy(tabela[posicao], valor);
}

// Função para obter o valor associado a uma chave na tabela hash
char* obterValor(char* chave, char** tabela) {
    // Retornar o valor na posição correspondente ao hash da chave

    int posicao = calcularHash(chave);
    printf("Obtendo valor da chave '%s' na posicao %d\n", chave, posicao);

    return tabela[posicao];
}

// Função para verificar se uma chave está na tabela hash
int contemChave(char* chave, char** tabela) {

    // Obter o tamanho da string na posição do hash da chave
    int posicao = calcularHash(chave);
    int tamanho = strlen(tabela[posicao]);

    // Verificar se a entrada na tabela contém algum valor
    int contem = 0;
    if(tamanho > 0) 
    {
        contem = 1;
    }

    printf("A chave '%s' está na posicao %d? %s\n", chave, posicao, contem ? "Sim" : "Nao");

    return contem;
}

// Função para remover uma chave da tabela hash
void removerChave(char* chave, char** tabela) {
    // Atribuir uma string vazia à posição correspondente ao hash da chave

    int posicao = calcularHash(chave);
    printf("Removendo chave '%s' da posição %d\n", chave, posicao);
    strcpy(tabela[posicao], "");
}
