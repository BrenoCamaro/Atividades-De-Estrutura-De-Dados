#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    char expressao[] = "(1 + (2 * 3))";
    if (esta_balanceado(expressao)) {
        printf("A expressao esta balanceada.\n");
    } else {
        printf("A expressao não esta balanceada.\n");
    }
    return 0;
}
