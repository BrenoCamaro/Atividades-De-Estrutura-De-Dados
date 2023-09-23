typedef struct Objeto{
    char valor;
    struct Objeto* proximo_objeto;
}Objeto;

typedef struct Pilha{
    Objeto* topo;
    int quantidade_objetos;
}Pilha;

Pilha* pilha(); 

void empilhar(Objeto* obj, Pilha* p);

Objeto* desempilhar (Pilha* p);