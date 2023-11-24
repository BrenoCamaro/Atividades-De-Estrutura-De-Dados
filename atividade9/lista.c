#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(float valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    if(no == NULL)
    {
        perror("erro ao alocar memoria");
        exit(1);
    }
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* cabeca, No* no){
    if(cabeca != NULL)
    {
        if(cabeca->proximo_no == NULL)
        {
            cabeca->proximo_no = no;
        }
        else
        {
            lista_inserir_no(cabeca->proximo_no, no);
        }
    }
}

void lista_inserir_no_ordenado(No** cabeca, No* no){
    if(*cabeca != NULL)
    {
        if((*cabeca)->valor >= no->valor)
        {
            no->proximo_no = *cabeca;
            *cabeca = no;
        }
        else if((*cabeca)->proximo_no != NULL)
        {
            lista_inserir_no_ordenado(&(*cabeca)->proximo_no, no);
        }
        else
        {
            (*cabeca)->proximo_no = no;
        }
    }
}

void lista_imprimir(No* cabeca){
    if(cabeca != NULL)
    {
        printf("%.2f ", cabeca->valor);
        lista_imprimir(cabeca->proximo_no);
    }
}

int lista_quantidade_nos(No* cabeca)
{
    if(cabeca != NULL)
    {
        return 1 + lista_quantidade_nos(cabeca->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* cabeca){
    if(cabeca != NULL)
    {
        return no(cabeca->valor, lista_copiar(cabeca->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* cabeca, No* cabeca2){
    lista_inserir_no(cabeca, cabeca2);
}

void lista_liberar(No* cabeca){
    if(cabeca != NULL)
    {
        lista_liberar(cabeca->proximo_no);
        free(cabeca);
    }
}