#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main()
{
    arvore_binaria arvore;
    arvore.raiz = NULL;
    int opcao;
    int valor;
    int chave;
    int menor = -1;
    int maior = -1;

    do{
        printf("\n\n0 - Sair\n1 - Inserir\n2 - Imprimir em ordem\n3 - Imprimir em pre-ordem\n4 - Imprimir em pos-ordem\n5 - Busca\n6 - Remover\n7 - Minimo e maximo\n8 - Limpar tela\n\n");
        scanf("%d",  &opcao);

        switch(opcao){
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("\nInforme um valor inteiro: ");
                scanf("%d", &valor);
                inserir(&arvore, valor);
                break;
            case 2:
                percorrer_em_ordem(arvore.raiz);
                break;
            case 3:
                percorrer_em_pre_ordem(arvore.raiz);
                break;
            case 4:
                percorrer_em_pos_ordem(arvore.raiz);
                break;
            case 5:
                printf("\nInforme o valor que procura: ");
                scanf("%d", &chave);
                printf("\nResultado da busca: %d ", busca(arvore.raiz, chave));
                break;
            case 6:
                printf("\nInforme o valor a ser removido: ");
                scanf("%d", &valor);
                arvore.raiz = remover(arvore.raiz, valor);
                break;
            case 7:
                encontrar_menor_maior(arvore.raiz, &menor, &maior); 
                printf("\nMenor valor na arvore: %d\n", menor);
                printf("\nMaior valor na arvore: %d\n", maior);    
                break;
            case 8:
                system("cls");
                break;
            default:
                printf("\nOpcao invalida...\n");
        }
    }while(opcao != 0);

    return 0;
}