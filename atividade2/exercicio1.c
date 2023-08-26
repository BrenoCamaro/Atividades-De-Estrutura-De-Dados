// Autor: Breno Camarô Arraes - uc22200177
// Soma dos elementos de um array. Escreva uma função que recebe um array de números inteiros e retorna a soma de 
// todos os elementos;
#include <stdio.h>
#include <stdlib.h>

int somaArray( int array[], int num ) /* Função que retorna a soma de todos os elementos do array */
{
    int i; /* Variável que controla o laço de repetição, isto é , o contador */
    int soma = 0; /* Variavel que conterá a soma dos elementos do array */

    for(i = 0; i < num; i++)
    {
        soma = soma + array[i];
    }
    return soma;
}

int main()
{   
    int i; /* Variável que controla o laço de repetição, isto é , o contador */
    int tam = 0;
    int resultado; /* Recebe a soma dos elementos do array */

    system("cls"); /* Limpa o prompt de comando */

    printf("\n*-----------------------------------------------------*\n"  );
    printf("                      SOMA ARRAY"                                         );
    printf("\n*-----------------------------------------------------*\n"  );

    printf("Informe o tamanho do vetor: ");
    scanf("%i", &tam);

    int vetor[tam];

    for(i = 0; i < tam; i++)
    {
        printf("\nInforme o valor da posicao[%i]: ", i);
        fflush(stdin); /* Esvazia o buffer do teclado */
        scanf("%i", &vetor[i]);
    }

    resultado = somaArray(vetor, tam);

    printf("\n*-----------------------------------------------------*\n"  );
    printf("     A soma dos elementos do array e: %i", resultado);
    printf("\n*-----------------------------------------------------*\n"  );
    return 0;
}