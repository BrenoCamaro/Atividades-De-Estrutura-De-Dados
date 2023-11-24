typedef struct No{
    float valor;
    struct No* proximo_no;
} No;

No* no(float valor, No* proximo_no);
void lista_inserir_no(No* cabeca, No* no);
void lista_inserir_no_ordenado(No** cabeca, No* no);
void lista_imprimir(No* cabeca);
int lista_quantidade_nos(No* cabeca);
No* lista_copiar(No* cabeca);
void lista_concatenar(No* cabeca, No* cabeca2);
void lista_liberar(No* cabeca);