#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_no(char valor, No* ponteiro){
    No* novo_no = (No *) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo_no = ponteiro;

    return novo_no;
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
        return criar_no(cabeca->valor, copiar_lista(cabeca->proximo_no));
    }

    return NULL;    
    
}

void concatenar_listas(No* cabeca1, No* cabeca2){
    lista_inserir_no(cabeca1, cabeca2);
}

/* NOVAS FUNÇÕES */
int lista_verificar_existencia(No* cabeca, char valor_busca){
    if(cabeca != NULL)
    {
        if(cabeca->valor == valor_busca)
        {
            return 1;
        }
        else
        {
            if(lista_verificar_existencia(cabeca->proximo_no, valor_busca) == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

int lista_verificar_ocorrencias(No* cabeca, char valor){
    if(cabeca == NULL)
    {
        return 0;
    }
    else
    {
        if(cabeca->valor == valor)
        {
            return 1 + lista_verificar_ocorrencias(cabeca->proximo_no, valor);
        }
        else
        {
            return lista_verificar_ocorrencias(cabeca->proximo_no, valor);
        }
        
    }
}

void lista_imprimir_inversa(No* cabeca){
    if(cabeca == NULL)
    {
        printf("\nERRO.... Nao existe nos na lista! \n");
        return;
    }
    else
    {
        if(cabeca->proximo_no == NULL)
        {
            printf("%c ", cabeca->valor); /* Imprime o último no */
        }
        else
        {
            lista_imprimir_inversa(cabeca->proximo_no); /* Chama a recursividade antes de imprimir para que as impressoes funcionem como pilha */
            printf("%c ", cabeca->valor);
        }
    }
}

void lista_atribuir_i(No* cabeca){
    if(cabeca == NULL)
    {
        printf("\nErro... Nao existe nos na lista! \n");
    }

    int indice = 0;
    No* temporario = cabeca;

    while(temporario != NULL) /* Atribui indices para cada no */
    {
        temporario->indice = indice;
        indice++;
        temporario = temporario->proximo_no;
    }
}

void lista_inserir_no_i(No* cabeca, int i, No* no){
    if(cabeca == NULL)
    {
        printf("\nErro... Nao existe nos na lista! \n");
    }
    else
    {
        if(i == 0)
        {
            no->proximo_no = cabeca;
            imprimir_lista(no);
        }
        else
        {
            if((i - 1) == cabeca->indice)
            {
                no->proximo_no = cabeca->proximo_no;
                cabeca->proximo_no = no;
            }
            else
            {
                lista_inserir_no_i(cabeca->proximo_no, i, no);
            }
            //imprimir_lista(cabeca);
        }
    }
}

void lista_remover_no_i(No** cabeca, int i){
     No* temp = *cabeca;
     No* prev = NULL;

    // Caso especial: Remover o nó cabeça
    if (i == 0 && temp != NULL) {
        *cabeca = temp->proximo_no;
        free(temp);
        return;
    }

    // Encontrar o nó a ser removido
    int current_index = 0;
    while (temp != NULL && current_index != i) {
        prev = temp;
        temp = temp->proximo_no;
        current_index++;
    }

    // Verificar se o índice é válido
    if (temp == NULL) {
        printf("Índice inválido. Nó não encontrado.\n");
        return;
    }

    // Desconectar o nó da lista
    prev->proximo_no = temp->proximo_no;

    // Liberar a memória alocada para o nó removido
    free(temp);
}


void lista_remover_no(No** cabeca, char valor_busca){
    No* current = *cabeca;
    No* prev = NULL;

    // Percorrer a lista
    while (current != NULL) {
        // Verificar se o valor do nó atual é igual ao valor de busca
        if (current->valor == valor_busca) {
            // Caso seja o nó cabeça, ajustar o ponteiro da cabeça
            if (prev == NULL) {
                *cabeca = current->proximo_no;
                free(current);
                current = *cabeca;
            } else {
                // Caso contrário, ajustar os ponteiros para remover o nó
                prev->proximo_no = current->proximo_no;
                free(current);
                current = prev->proximo_no;
            }
        } else {
            // Se o valor não corresponder, avançar na lista
            prev = current;
            current = current->proximo_no;
        }
    }

}


void liberar(No* cabeca){
    if(cabeca != NULL)
    {
        liberar(cabeca->proximo_no);
        free(cabeca);
    }
}