typedef struct No{
    char valor;
    struct No* proximo_no;
}No;

No* criar_no(char valor, No* ponteiro);
void agrupar_no(No* cabeca, No* no);
void imprimir_lista(No* cabeca);
int quantidade_de_nos(No* cabeca);
No* copiar_lista(No* cabeca);
void concatenar_listas(No* cabeca1, No* cabeca2);
void liberar(No* cabeca);