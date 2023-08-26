// Autor: Breno Camarô Arraes - uc22200177
// Multiplicar elementos de dois arrays. Escreva uma função que recebe dois arrays de números inteiros com o mesmo 
// tamanho e retorna um novo array com os elementos resultantes da multiplicação dos elementos dos dois arrays.
#include <stdio.h>
#include <stdlib.h>

typedef struct vetores
{
    int vetorResultante[10];

}vetores;

vetores multiplicaArray(int vetorUm[], int vetorDois[])
{
    vetores arrayMultiplicado;
    int i;

    for(i = 0; i < 10; i++)
    {
        arrayMultiplicado.vetorResultante[i] = vetorUm[i] * vetorDois[i];
    }
    return arrayMultiplicado;
}

int main()
{
    int i; /* Variável que controla o laço de repetição, isto é , o contador */
    int vetorUm[10];
    int vetorDois[10];
    vetores vetorResultado;


    system("cls"); /* Limpa o prompt de comando */

    printf("\n*-----------------------------------------------------*\n"  );
    printf("                    MULTIPLICAR ARRAYS"                       );
    printf("\n*-----------------------------------------------------*\n"  );

    printf("\n*-------------------------------*\n");
    printf("             VETOR 1:\n");
    printf("*-------------------------------*\n");

    for(i = 0; i < 10; i++)
    {
        printf("\nInforme o valor da posicao[%i]: ", i);
        fflush(stdin); /* Esvazia o buffer do teclado */
        scanf("%i", &vetorUm[i]);
    }


    printf("\n*-------------------------------*\n");
    printf("             VETOR 2:\n");
    printf("*-------------------------------*\n");

    for(i = 0; i < 10; i++)
    {
        printf("\nInforme o valor da posicao[%i]: ", i);
        fflush(stdin); /* Esvazia o buffer do teclado */
        scanf("%i", &vetorDois[i]);
    }

    vetorResultado = multiplicaArray(vetorUm, vetorDois);

    printf("\n*-----------------------------------------------------*\n"  );
    for(i = 0; i < 10; i++)
    {
        printf("%i ", vetorResultado.vetorResultante[i]);
    }
    return 0;
}