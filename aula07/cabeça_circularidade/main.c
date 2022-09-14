//listas com cabeça e circularidade

// a cabeça não guarda valor da lista, é apenas um local referência na 
// memória que evita o tratamento do caso de anterior ser nulo

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct est {
    int chave;
    struct est* prox; //forma de atribuir uma propriedade para o próprio objeto
} NO;

typedef struct {
    NO* cabeça;
} LISTA_CAB;

void inicializar(LISTA_CAB * l) {
    l -> cabeça = (NO*) malloc(sizeof(NO));
    l -> cabeça -> prox = l-> cabeça; //o último elemento aponta para o primeiro(circularidade)
}

int contarChave(LISTA_CAB * l) {
    int resp = 0;
    NO* p = l -> cabeça -> prox;// a cabeça não faz parte do problema
    while(p != l -> cabeça) { //como a lista é circular, deve parar quando retornar ao início
        resp++;
        p = p -> prox;
    }

    return(resp);
}

bool excluir(LISTA_CAB*l, int ch) {

    NO* ant;
    NO* atual = busca(l, ch, &ant); //fingir que foi implementada
    if(!atual) return(false);
    ant -> prox = atual -> prox;
    free(atual);
    return(true);

}