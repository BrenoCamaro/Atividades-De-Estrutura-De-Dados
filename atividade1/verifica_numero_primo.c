// Autor: Breno Camarô Arraes
// Matrícula: uc2200177
// Crie um programa em linguagem C que recebe um número e imprime no console: 0 - se o número não for primo;
// 1 - se o número for primo.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0;
 
    system("cls"); /* Limpa o prompt de comando */

    printf("-----------------------------------------\n");
    printf("     VERIFICADOR DE NUMEROS PRIMOS \n");
    printf("----------------------------------------- ");

    printf("\n\nInforme um valor ( -1 para terminar ): ");
    fflush(stdin); /* Esvazia o buffer do teclado */
    scanf("%d", &numero);

    while( numero != -1 )
    {
        if( numero <= 1 )
            printf("\n0 - (NAO PRIMO!) \n"); 
    else if( numero == 2 )
            printf("\n1 - ( PRIMO! ) \n");
        else if( numero % 2 == 0 )
            printf("\n0 - (NAO PRIMO!) \n");
        else if ( numero == 3 )
            printf("\n1 - ( PRIMO! ) \n");
        else if( numero % 3 == 0 )
            printf("\n0 - (NAO PRIMO!) \n");
        else if ( numero == 5 )
            printf("\n1 - ( PRIMO! ) \n");
        else if( numero % 5 == 0 )
            printf("\n0 - (NAO PRIMO!) \n");
        else if ( numero == 7 )
            printf("\n1 - ( PRIMO! ) \n");
        else if( numero % 7 == 0 )
            printf("\n0 - (NAO PRIMO!) \n");
        else printf("\n1 - ( PRIMO! ) \n");           
    
        printf("\nInforme um valor ( -1 para terminar ): ");
        fflush(stdin); /* Esvazia o buffer do teclado */
        scanf("%d", &numero);
    }
    return 0;
}
