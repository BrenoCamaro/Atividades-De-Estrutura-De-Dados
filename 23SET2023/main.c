#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char* argv){

    Objeto obj1;
    obj1.valor = 'A';
    Objeto obj2;
    obj2.valor = 'B';
    Objeto obj3;
    obj3.valor = 'C';
    Pilha* p = pilha(); //Função que retorna uma pilha

    empilhar(&obj1, p);
    empilhar(&obj2, p);
    empilhar(&obj3, p);

    Objeto* obj;
    do{
        obj =  desempilhar(p);
        if(obj != NULL){
            printf("%c\n", obj->valor);
        }
    }while(obj != NULL);

    desempilhar(p);

    exit(0);
}