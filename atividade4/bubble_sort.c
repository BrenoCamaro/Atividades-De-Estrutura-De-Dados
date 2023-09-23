// Autor: Breno Camarô Arraes - uc22200177
// Aquivo que contem a implementação a função bubbleSort 


#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void bubbleSort(int vetor[], int n) {
   int i, j, temp;

   for (i = 0; i < n-1; i++) 
   {     
       for (j = 0; j < n-i-1; j++)
        { 
           if (vetor[j] > vetor[j+1]) 
           {
              temp = vetor[j];
              vetor[j] = vetor[j+1];
              vetor[j+1] = temp;
           }
       }
   }
}