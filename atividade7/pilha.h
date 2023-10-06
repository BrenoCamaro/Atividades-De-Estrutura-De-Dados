typedef struct Pilha {
    char dado;
    struct Pilha* proximo;
} Pilha;


Pilha* criar_pilha();
Pilha* incluir(Pilha* pilha, char novo_dado);
Pilha* remover(Pilha* pilha);

int esta_vazia(Pilha* pilha);
int esta_balanceado(char* expressao);