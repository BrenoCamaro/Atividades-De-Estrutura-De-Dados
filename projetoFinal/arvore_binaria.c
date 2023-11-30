#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

void inserir_direita(No* no, int valor){
    if(no->direita == NULL)
    {
        No* novo_no = (No*) malloc(sizeof(No));
        novo_no->conteudo = valor;
        novo_no->esquerda = NULL;
        novo_no->direita = NULL;

        no->direita = novo_no;
    }
    else
    {
        if(valor < no->direita->conteudo)
        {
            inserir_esquerda(no->direita, valor);
        }
        if(valor > no->direita->conteudo)
        {
            inserir_direita(no->direita, valor);
        }
    }
}

void inserir_esquerda(No* no, int valor){
    if(no->esquerda == NULL)
    {
        No* novo_no = (No*) malloc(sizeof(No));
        novo_no->conteudo = valor;
        novo_no->esquerda = NULL;
        novo_no->direita = NULL;

        no->esquerda = novo_no;
    }
    else
    {
        if(valor < no->esquerda->conteudo)
        {
            inserir_esquerda(no->esquerda, valor);
        }
        if(valor > no->esquerda->conteudo)
        {
            inserir_direita(no->esquerda, valor);
        }
    }
}


void inserir(arvore_binaria* arvore, int valor){
    if(arvore->raiz == NULL)
    {
        No* novo_no = (No*) malloc(sizeof(No));
        novo_no->conteudo = valor;
        novo_no->esquerda = NULL;
        novo_no->direita = NULL;

        arvore->raiz = novo_no;
    }
    else
    {
        if(valor < arvore->raiz->conteudo)
        {
            inserir_esquerda(arvore->raiz, valor);
        }
        if(valor > arvore->raiz->conteudo)
        {
            inserir_direita(arvore->raiz, valor);
        }
    }
}

void percorrer_em_ordem(No* raiz){
    if(raiz == NULL)
    {
        
    }
    else
    {
 
        percorrer_em_ordem(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        percorrer_em_ordem(raiz->direita);
    }
}

void percorrer_em_pre_ordem(No* raiz){
    if(raiz == NULL)
    {
        
    }
    else
    {
        printf("%d ", raiz->conteudo);
        percorrer_em_pre_ordem(raiz->esquerda);
        percorrer_em_pre_ordem(raiz->direita);
    }
}

void percorrer_em_pos_ordem(No* raiz){
    if(raiz != NULL)
    {
        percorrer_em_pos_ordem(raiz->esquerda);
        percorrer_em_pos_ordem(raiz->direita);
        printf("%d ", raiz->conteudo);

    }
}


int busca(No* raiz, int chave){
    if(raiz == NULL)
    {
        return 0;
    }
    else
    {
        if(raiz->conteudo == chave)
        {
            return 1;
        }
        else
        {
            if(chave < raiz->conteudo)
            {
                return busca(raiz->esquerda, chave);
            }
            else
            {
                return busca(raiz->direita, chave);
            }
        }

    }
}

void encontrar_menor_maior(No* raiz, int* menor, int* maior) {
    if (raiz != NULL) {
        encontrar_menor_maior(raiz->esquerda, menor, maior);

        if (raiz->conteudo < *menor || *menor == -1) {
            *menor = raiz->conteudo;
        }

        if (raiz->conteudo > *maior || *maior == -1) {
            *maior = raiz->conteudo;
        }

        encontrar_menor_maior(raiz->direita, menor, maior);
    }
}

No* remover(No* raiz, int chave)
{
    if(raiz == NULL)
    {
        printf("\nValor nao encontrado! \n");
        return NULL;
    }
    else
    {
        if(raiz->conteudo == chave)
        {
            /* Remove nós folhas (nós sem filhos) */
            if(raiz->esquerda == NULL && raiz->direita == NULL )
            {
                free(raiz);
                return NULL;
            }
            else
            {
                /* Remove nós com apenas 1 filho */
                if(raiz->esquerda == NULL || raiz->direita == NULL)
                {
                    No* aux;
                    if(raiz->esquerda != NULL)
                    {
                        aux = raiz->esquerda;
                        free(raiz);
                        return aux;
                    }
                    else
                    {
                        aux = raiz->direita;
                        free(raiz);
                        return aux;
                    }
                }
                else
                {
                    No* aux = raiz->esquerda;
                    while(aux->direita != NULL)
                    {
                        aux = aux->direita;
                    }
                        raiz->conteudo = aux->conteudo;
                        aux->conteudo = chave;
                        raiz->esquerda = remover(raiz->esquerda, chave);
                        return raiz;
                }
            }
        }
        else
        {
            if(chave < raiz->conteudo)
            {
                raiz->esquerda = remover(raiz->esquerda, chave);
            }
            else
            {
                raiz->direita = remover(raiz->direita, chave);
            }
            return raiz;
        }
    }
}


