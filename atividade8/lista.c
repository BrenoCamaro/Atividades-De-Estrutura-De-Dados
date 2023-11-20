#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_no(char valor, No* ponteiro){
    No* novo_no = (No *) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo_no = ponteiro;

    return novo_no;
}

void agrupar_no(No* cabeca, No* no){
    if(cabeca != NULL)
    {
        if(cabeca->proximo_no != NULL)
        {
            agrupar_no(cabeca->proximo_no, no);
        }
        else
        {
            cabeca->proximo_no = no;
        }
    }

}

void imprimir_lista(No* cabeca){
    if(cabeca != NULL)
    {
        printf("%c ", cabeca->valor);
        imprimir_lista(cabeca->proximo_no);
    }
}

int quantidade_de_nos(No* cabeca){
    if(cabeca != NULL)
    {
        return 1 + quantidade_de_nos(cabeca->proximo_no);
    }
    else
    {
        return 0;
    }
}

No* copiar_lista(No* cabeca){
    if(cabeca != NULL)
    {
        return criar_no(cabeca->valor, cabeca->proximo_no);
    }
    else
    {
        return NULL;    
    }
}
void concatenar_listas(No* cabeca1, No* cabeca2){
    agrupar_no(cabeca1, cabeca2);
}

void liberar(No* cabeca){
    if(cabeca != NULL)
    {
        liberar(cabeca->proximo_no);
        free(cabeca);
    }
}