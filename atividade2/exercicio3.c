// Autor: Breno Camarô Arraes - uc22200177
//	Verificar se um elemento existe no array Escreva uma função que recebe um array de strings e uma string de busca, 
// 	e retorna "1" se a string de busca existe no array, ou "0" caso não exista.

#include <stdio.h>
#include <stdlib.h>

int BuscadorDeString(char *array[], int tamanho, char *buscador);

int main()
{
    char *array[] = {"MIT", "Stanford", "Havard", "Columbia"};
    int tamanho = sizeof(array) / sizeof(array[0]);
    char *buscador = "Havard";
	int resultado;

    system("cls"); /* Limpa o prompt de comando */

    printf("\n*-----------------------------------------------------*\n"  );
    printf("                    BUSCADOR DE STRING"                       );
    printf("\n*-----------------------------------------------------*\n"  );



     resultado = BuscadorDeString(array, tamanho, buscador);

	printf("\n*-----------------------------------------------------*\n"  );
    printf("                    RESULTADO: %i", resultado                 );
    printf("\n*-----------------------------------------------------*\n"  );
	return 0;
}

int BuscadorDeString(char *array[], int tamanho, char *buscador) 
{
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], buscador) == 0) {
            return 1;
        }
    }
    return 0;
}