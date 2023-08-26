// Autor: Breno Camarô Arraes - uc22200177
// Maior e menor elemento do array. Escreva uma função que recebe um array de números inteiros 
// e retorna o menor e o maior elemento do array.

#include <stdio.h>
#include <stdlib.h>

typedef struct menorEmaiorValor
{
    int maiorValor;
    int menorValor;
}menorEmaiorValor;

menorEmaiorValor maiorEmenor(int array[], int num ); /* Protótipo função que retorna o menor e o maior elemento de um array */

int main()
{
    int i; /* Variável que controla o laço de repetição, isto é , o contador */
    int tam = 0; /* Tamanho do vetor */
    menorEmaiorValor x;

    system("cls"); /* Limpa o prompt de comando */

    printf("\n*-----------------------------------------------------*\n"  );
    printf("                      MENOR E MAIOR"                          );
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

    x = maiorEmenor(vetor, tam);

    printf("\n*-----------------------------------------------------*\n"  );
    printf("     MAIOR = %i  e  MENOR = %i", x.maiorValor, x.menorValor   );
    printf("\n*-----------------------------------------------------*\n"  );

    return 0;
}

menorEmaiorValor maiorEmenor(int array[], int num ) /* Função que retorna o menor e o maior elemento de um array */
{
    int i = 0;
    menorEmaiorValor p;

    p.maiorValor = array[0];
    p.menorValor = array[0];

    while( i < num )
    {
        if( array[i] >= p.maiorValor )
            p.maiorValor = array[i];

        i++;
    }
    i = 0;
    while( i < num )
    {
        if( array[i] <= p.menorValor )
            p.menorValor = array[i];

        i++;
    }
    return p;
}