#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

#define MAX_WORDS 1000
#define MAX_CHAR 100


int main(int argc, char *argv[]) {
   if(argc != 3) {
      printf("Uso: ./programa <arquivo_entrada> <arquivo_saida>\n");
      return 1;
   }

   FILE *file = fopen(argv[1], "r");
   if(file == NULL) {
      printf("Não foi possível abrir o arquivo %s\n", argv[1]);
      return 1;
   }

   char words[MAX_WORDS][MAX_CHAR];
   int i = 0;

   while(fscanf(file, "%s", words[i]) != EOF && i < MAX_WORDS) {
      i++;
   }

   fclose(file);

   bubbleSort(words, i);

   file = fopen(argv[2], "w");
   if(file == NULL) {
      printf("Não foi possível abrir o arquivo %s\n", argv[2]);
      return 1;
   }

   for(int j = 0; j < i; j++) {
      fprintf(file, "%s\n", words[j]);
   }

   fclose(file);

   return 0;
}
