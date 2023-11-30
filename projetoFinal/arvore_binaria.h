/* Estruturas */

struct no{
    int conteudo;
    struct no* esquerda;
    struct no* direita;
};

typedef struct no No;

struct arvore_binaria{
    No* raiz;
};

typedef struct arvore_binaria arvore_binaria;

/* Funções  */
void inserir_esquerda(No* no, int valor);
void inserir_direita(No* no, int valor);
void inserir(arvore_binaria* arvore, int valor);
void percorrer_em_ordem(No* raiz);
void percorrer_em_pre_ordem(No* raiz);
void percorrer_em_pos_ordem(No* raiz);
int busca(No* raiz, int chave);
void encontrar_menor_maior(No* raiz, int* menor, int* maior);
No* remover(No* raiz, int chave);


