#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int valor;
    struct no * prox;
} no;

typedef no * pilha;

void criar(pilha * topo){
    *topo = NULL;
}

bool push(pilha * topo, int valor){
    pilha novo = (pilha)malloc(sizeof (no));
    if(novo!=NULL){
        novo->valor = valor;
        novo->prox = *topo;
        *topo = novo;
        return true;
    }
    return false;
}

bool pop(pilha * topo, int * valor){
    if(*topo!=NULL){
        pilha aux = *topo;
        *valor = aux->valor;
        *topo = aux->prox;
        free(aux);
        return true;
    }
    return false;
}

bool migrate(pilha * topo1, pilha * topo2, int * valor){
    if(*topo1 != NULL && pop(topo1, valor) && push(topo2, *valor)) {
        return true;
    }
    return false;
}