#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criar_pilha() {
    return NULL;
}

Pilha* incluir(Pilha* pilha, char novo_dado) {
    Pilha* novo_item = (Pilha*) malloc(sizeof(Pilha));
    novo_item->dado = novo_dado;
    novo_item->proximo = pilha;
    return novo_item;
}

Pilha* remover(Pilha* pilha) {
    if (pilha != NULL) {
        Pilha* temp = pilha->proximo;
        free(pilha);
        return temp;
    }
    return NULL;
}

int esta_vazia(Pilha* pilha) {
    return (pilha == NULL);
}

int esta_balanceado(char* expressao) {
    Pilha* pilha = criar_pilha();
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            pilha = incluir(pilha, expressao[i]);
        } else if (expressao[i] == ')') {
            if (esta_vazia(pilha)) {
                return 0;
            } else {
                pilha = remover(pilha);
            }
        }
    }
    int balanceado = esta_vazia(pilha);
    free(pilha);
    return balanceado;
}
