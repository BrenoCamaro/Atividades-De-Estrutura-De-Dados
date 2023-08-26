// Autor: Breno Camarô Arraes - uc22200177
// Contar a quantidade de ocorrências de um elemento no array. Escreva uma função que recebe um array de números 
// inteiros e um número inteiro de busca, e retorna a quantidade de vezes que o número de busca aparece no array.
#include <stdio.h>
#include <stdlib.h>

int contadorDeElemento(int array[], int tamanho, int elemento)
{
    int i;
    int contadorDeElementoRepetido = 0;

    for( i = 0; i < tamanho; i++)
    {
        if( elemento == array[i] )
            contadorDeElementoRepetido++;
    }
    return contadorDeElementoRepetido;
}

int main()
{   
    int i; /* Variável que controla o laço de repetição, isto é , o contador */
    int tam = 0; /* Tamanho do array */
    int quantidadeDoElemento; /* Recebe a quantidade de vezes que o elemento buscado aparece no array */
    int elemento; /* Elemento que desejo buscar no array */

    system("cls"); /* Limpa o prompt de comando */

    printf("\n*-----------------------------------------------------*\n"  );
    printf("             CONTADOR DE ELEMENTO NO ARRAY"                   );
    printf("\n*-----------------------------------------------------*\n"  );

    printf("Informe o tamanho do vetor: ");
    fflush(stdin); /* Esvazia o buffer do teclado */
    scanf("%i", &tam);

    int vetor[tam];

    for(i = 0; i < tam; i++)
    {
        printf("\nInforme o valor da posicao[%i]: ", i);
        fflush(stdin); 
        scanf("%i", &vetor[i]);
    }

    printf("\nInforme o elemento que deseja buscar: ");
    fflush(stdin);
    scanf("%i", &elemento);

    quantidadeDoElemento = contadorDeElemento(vetor, tam, elemento);

    printf("\n*-----------------------------------------------------*\n"  );
    printf("           ELEMENTO APARECE: %i VEZES", quantidadeDoElemento  );
    printf("\n*-----------------------------------------------------*\n"  );
    return 0;
}