// Autor: Breno Camarô Arraes - uc22200177
// programa deve implementar o algoritmo bubble sort para ordenar uma lista de números passados na chamada do programa e 
// imprimir a lista dos números ordenados como saída.

#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"


int main(int argc, char *argv[]) {
   int n = argc - 1;
   int vetor[n];

   for (int i = 0; i < n; i++) 
   {
       vetor[i] = atoi(argv[i+1]);
   }

   bubbleSort(vetor, n);

   printf("Vetor ordenado: \n");

   for (int i=0; i <n; i++)
       printf("%d ", vetor[i]);
       
   return 0;
}
