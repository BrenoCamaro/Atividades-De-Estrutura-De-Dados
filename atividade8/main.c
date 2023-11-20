#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv)
{
    No* n0 = criar_no('A', NULL);  
    No* n1 = criar_no('B', NULL);
    No* n2 = criar_no('C', NULL);
    No* n3 = criar_no('D', NULL);
    int numero_de_nos;

    agrupar_no(n0, n1); /* Função que insere um no na lista. */
    agrupar_no(n0, n2);
    agrupar_no(n0, n3);

    imprimir_lista(n0);
    printf("\n");

    No* n4 = copiar_lista(n0);

    imprimir_lista(n4);
    printf("\n");

    //concatenar_listas(n0, n4);

    imprimir_lista(n0);
    printf("\n");
    numero_de_nos = quantidade_de_nos(n0);
    printf("Quantidade de nos = %d", numero_de_nos);
    return 0;
}