#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char letra;
    struct no * prox;
} no;

typedef no * pilha;

void criar(pilha * topo){
    *topo = NULL;
}

bool push(pilha * topo, char letra){
    pilha novo = (pilha)malloc(sizeof (no));
    if(novo!=NULL){
        novo->letra = letra;
        novo->prox = *topo;
        *topo = novo;
        return true;
    }
    return false;
}

bool pop(pilha * topo, char * letra){
    if(*topo!=NULL){
        pilha aux = *topo;
        *letra = aux->letra;
        *topo = aux->prox;
        free(aux);
        return true;
    }
    return false;
}

bool migrate(pilha * topo1, pilha * topo2, char * letra){
    if(*topo1 != NULL && pop(topo1, letra) && push(topo2, *letra)) {
        return true;
    }
    return false;
}

void exibir(pilha * topo){
    if(*topo!=NULL){
        pilha aux = *topo;
        while(aux!=NULL){
            printf("%c", aux->letra);
            aux = aux->prox;
        }
        printf("\n");
    }
}


bool palindromo(pilha * topo1, pilha * topo2){
    for (int i = 0; i < 255; ++i) {
        char letra01, letra02;
        pop(topo1, &letra01);
        pop(topo2, &letra02);
        if(letra01 != letra02){
            return false;
        }
    }
     return true;
}

int main (){
    int opcao = 0;
    char frase[255], frasereduzida[255];
    pilha topo, topo2;
    criar(&topo);
    criar(&topo2);
    printf("\nSistema para verificar palindromos");
    printf("\nDigite o texto para verificar se é um palindromo.");
    scanf("%[^\n]", frase);
    int c = 0;
    for (int i = 0; i < strlen(frase); ++i) {
        if (isalnum(frase[i])){
            frasereduzida[c] = frase[i];
            c++;
        }
    }
    frasereduzida[c] = '\0';
    printf("%s", frasereduzida);
    for (int i = 0; i < strlen(frasereduzida) ; ++i) {
        push(&topo, frasereduzida[i]);
        push(&topo2, frasereduzida[strlen(frasereduzida) - (i+1)]);
    }
        exibir(&topo);
        exibir(&topo2);
    if (palindromo(&topo, &topo2)) {
        printf("\nE um palindromo.");
    } else {
        printf("\nNão é um palindromo.");
    }

    return 0;
}