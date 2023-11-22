#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv)
{
    No* n0 = criar_no('A', NULL);  
    No* n1 = criar_no('B', NULL);
    No* n2 = criar_no('C', NULL);
    No* n3 = criar_no('D', NULL);

    lista_inserir_no(n0, n1); 
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n3);
    
    printf("O valor 'C' existe: %d \n", lista_verificar_existencia(n0,'C')); /* Teste da função verificar_existencia */
    printf("Qtd de ocorrencias do valor 'D': %d \n", lista_verificar_ocorrencias(n0, 'D')); /* Teste da função verificar_ocorrencia */
    printf("\n");

    lista_imprimir_inversa(n0);   /* Teste da função imprimir_lista_inversa */
    printf("\n");

    No* n4 = criar_no('S', NULL);
    lista_atribuir_i(n0);          /* Função extra que atribui indices para os nos. Obs.: Use sempre que for trabalhar com indices*/
    lista_inserir_no_i(n0, 2, n4); /* Teste da função inserir_no_i */
    imprimir_lista(n0);            /* Imprimindo teste da função inserir_no_i */
    printf("\n");

    lista_remover_no_i(&n0, 2);     /* Teste da função remover_no_i */
    imprimir_lista(n0);             /* Imprimindo teste da função remover_no_i */
    printf("\n");

    lista_remover_no(&n0, 'B');      /* Teste da função remover_no */
    imprimir_lista(n0);              /* Imprimindo teste a função remover_no */
    
    return 0;
}