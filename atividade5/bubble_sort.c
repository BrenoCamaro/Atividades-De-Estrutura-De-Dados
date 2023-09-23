#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_CHAR 100

void bubbleSort(char arr[MAX_WORDS][MAX_CHAR], int n) {
   int i, j;
   char temp[MAX_CHAR];
   for (i = 0; i < n-1; i++) {     
       for (j = 0; j < n-i-1; j++) { 
           if (strcmp(arr[j], arr[j+1]) > 0) {
              strcpy(temp, arr[j]);
              strcpy(arr[j], arr[j+1]);
              strcpy(arr[j+1], temp);
           }
       }
   }
}