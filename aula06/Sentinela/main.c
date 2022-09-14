/* 

O sentinela tem o objetivo de acelerar o algoritmo de busca

Poupa o teste de verificar se o NO é nulo

 */

#include <stdlib.h>
#include <stdio.h>

typedef struct est {
    int chave;
    struct est* prox; //forma de atribuir uma propriedade para o próprio objeto
} NO;

typedef struct  {
    NO* inicio;
    NO* sent;
} LISTA_SENT;

void inicializar(LISTA_SENT * l) {
    l -> sent = (NO*) malloc(sizeof(NO));
    l -> inicio = l -> sent;
}

void exibir(LISTA_SENT * l) {
    NO* p = l -> inicio;
    while (p != l -> sent) // trocar o NULL por l -> sent
    {
        printf("%d ", p -> chave);
        p = p -> prox;
    }
    
}



