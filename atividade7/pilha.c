#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criar_pilha() {
    return NULL;
}

Pilha* incluir(Pilha* pilha, char novo_dado) {
    Pilha* novo_item = (Pilha*) malloc(sizeof(Pilha)); // Aloca memória para um novo item na pilha
    novo_item->dado = novo_dado; // Atribui o novo dado ao campo 'dado' do novo item
    novo_item->proximo = pilha; // Atribui o ponteiro para o topo da pilha ao campo 'proximo' do novo item
    return novo_item;  // Retorna um ponteiro para o novo item, que agora é o novo topo da pilha
}

Pilha* remover(Pilha* pilha) {
    if (pilha != NULL) { // verifica se a pilha não está vazia
        Pilha* temp = pilha->proximo; // cria um ponteiro temporário para o próximo elemento na pilha
        free(pilha); // Libera a memória alocada para o elemento no topo da pilha
        return temp; //retorna um ponteiro para um novo topo da pilha
    }
    return NULL;
}

int esta_vazia(Pilha* pilha) {
    return (pilha == NULL); //Retorna 1 se a pilha estiver vazia e 0 caso contrário
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
