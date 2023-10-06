#include <stdio.h>
#include "fila.h"

int main() {
    int n = 3;
    int quantum = 5;
    int tempo_execucao[] = {10, 5, 15};

    round_robin(n, quantum, tempo_execucao);

    return 0;
}
