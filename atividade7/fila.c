#include <stdio.h>
#include "fila.h"
#define MAX 10

void round_robin(int n, int quantum, int tempo_execucao[]) {
    int tempo_restante[MAX], i, tempo_atual = 0;

    for (i = 0; i < n; i++) {
        tempo_restante[i] = tempo_execucao[i];
    }

    while (1) {
        int finalizado = 1;
        for (i = 0; i < n; i++) {
            if (tempo_restante[i] > 0) {
                finalizado = 0;
                if (tempo_restante[i] > quantum) {
                    tempo_atual += quantum;
                    tempo_restante[i] -= quantum;
                } else {
                    tempo_atual += tempo_restante[i];
                    tempo_restante[i] = 0;
                    printf("O processo %d foi concluido no tempo %d.\n", i+1, tempo_atual);
                }
            }
        }
        if (finalizado == 1) {
            break;
        }
    }
}

