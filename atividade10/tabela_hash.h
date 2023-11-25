
#define TAM_ALFABETO 26
#define TAM_TABELA 1000
#define TAM_VALOR 100


int calcularHash(char* chave);


char** inicializarTabelaHash();

void inserirValor(char* chave, char* valor, char** tabela);

char* obterValor(char* chave, char** tabela);

int contemChave(char* chave, char** tabela);

void removerChave(char* chave, char** tabela);


