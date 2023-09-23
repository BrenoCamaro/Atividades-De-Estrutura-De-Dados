#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* pilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->quantidade_objetos = 0;


    return p;
}

void empilhar(Objeto* obj, Pilha* p){
    obj->proximo_objeto = p->topo; // obj aponta para quem está no topo da pilha;
    p->topo = obj; // agora o topo é esse objeto que acabei de empilhar
    p->quantidade_objetos++;
}

Objeto* desempilhar (Pilha* p){
    if(p->quantidade_objetos == 0){
        return NULL;
    }

    Objeto* obj = p->topo;
    p->topo = obj->proximo_objeto;
    p->quantidade_objetos--;

    return obj;
}