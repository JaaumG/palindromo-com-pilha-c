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

void criar(pilha * topo){ //função para criar a pilha
    *topo = NULL; //inicializa a pilha
}

bool push(pilha * topo, char letra){ //função para adicionar um elemento na pilha
    pilha novo = (pilha)malloc(sizeof (no)); //aloca um novo no
    if(novo!=NULL){ //verifica se o no foi alocado
        novo->letra = letra; //adiciona a letra no no
        novo->prox = (struct no *) *topo; //adiciona o proximo no
        *topo = novo; //adiciona o no na pilha
        return true;
    }
    return false;
}

bool pop(pilha * topo, char * letra){ //função para remover um elemento da pilha
    if(*topo!=NULL){ //verifica se a pilha não está vazia
        pilha aux = *topo; //cria um auxiliar para a pilha
        *letra = aux->letra; //adiciona a letra no auxiliar
        *topo = (pilha) aux->prox; //adiciona o proximo no
        free(aux); //libera o no da memoria
        return true;
    }
    return false;
}

bool clone(pilha * topo1, pilha * topo2){ //função para clonar uma pilha
    if(*topo1!=NULL){ //verifica se a pilha não está vazia
        pilha aux = *topo1; //cria um auxiliar para a pilha
        while(aux!=NULL){ //percorre a pilha
            push(topo2, aux->letra); //adiciona a letra no no
            aux = (pilha) aux->prox; //adiciona o proximo no
        }
        return true;
    }
    return false;
}

bool isPalindromo(pilha * topo1, pilha * topo2){ //função para verificar se é um palindromo
     while(*topo1!=NULL){ //percorre a pilha
        char letra01, letra02; //variaveis para armazenar as letras
        pop(topo1, &letra01); //remove a letra da pilha
        pop(topo2, &letra02); //remove a letra da pilha
        if(letra01 != letra02){ //verifica se as letras são iguais
            return false;
        }
    }
     return true;
}

int main (){
    char frase[255];//tamanho da frase
    pilha topo, topo2; //instanciação da pilha
    criar(&topo); //criação da pilha
    criar(&topo2); //criação da pilha
    printf("\nSistema para verificar palindromos.");
    printf("\nDigite o texto para verificar se e um palindromo.\n");
    scanf("%[^\n]", frase); //leitura da frase com metodo de leitura de string com espaço
    for (int i = 0; i < strlen(frase); ++i) { //percorre a frase
        if (isalnum(frase[i])){ //verifica se é um caracter alfanumerico
            push(&topo, frase[i]); //adiciona a pilha
        }
    }
    clone(&topo, &topo2); //clona a pilha para outra pilha
    if (isPalindromo(&topo, &topo2)) { //verifica se é um palindromo ou não
        printf("\nA frase: %s e um palindromo.", frase);
    } else {
        printf("\nA frase: %s nao e um palindromo.", frase);
    }
    return 0;
}