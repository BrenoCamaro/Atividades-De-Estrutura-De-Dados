typedef struct No{
    char valor;
    struct No* proximo_no;
    int indice;
}No;



No* criar_no(char valor, No* ponteiro);

void lista_inserir_no(No* cabeca, No* no);

void imprimir_lista(No* cabeca);

int quantidade_de_nos(No* cabeca);

No* copiar_lista(No* cabeca);

void concatenar_listas(No* cabeca1, No* cabeca2);

void liberar(No* cabeca);


/* Novas funções */
int lista_verificar_existencia(No* cabeca, char valor_busca);

int lista_verificar_ocorrencias(No* cabeca, char valor);

void lista_imprimir_inversa(No* cabeca);

void lista_atribuir_i(No* cabeca); /* Função que atribuirá indices - OBS.: Chame sempre que for trabalhar com indices */

void lista_inserir_no_i(No* cabeca, int i, No* no); 

void lista_remover_no_i(No** cabeca, int i); /* Passar como parâmetro &cabeca */

void lista_remover_no(No** cabeca, char valor_busca); /* Passar como parâmetro &cabeca */