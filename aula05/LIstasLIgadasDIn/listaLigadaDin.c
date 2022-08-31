#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct est {
    int chave;
    struct est* prox; //forma de atribuir uma propriedade para o próprio objeto
} NO; //elemento da lista("bolinhas")

typedef struct {
    NO* inicio; //ponteiro à posição de memória ocupado por um nó
} LISTA_LIG_DIN;

void inicializar(LISTA_LIG_DIN * l) {
    l -> inicio = NULL; //aponta para um endereço de memória inválido

}

int contar(LISTA_LIG_DIN * l) {
    int resp = 0;
    NO* p = l -> inicio;
    while(p != NULL) { //até encontrar uma ponteiro inválido
        resp++;
        p = p -> prox; 
    }
    return(resp);
}

/*

malloc (sizeof(NO)) -> aloca um nó em memória sempre que possível
retorna um endereço de memória(ponteiro)

sintaxe -> NO* p = (NO*) malloc(sizeof(NO));
p -> chave = 10; -> acessamos o nó e atribuímos uma chave 10

obs: Se p = NULL, sem memória disponível

*/

void anexar(LISTA_LIG_DIN * l, int ch) {

    NO* novo = (NO*) malloc(sizeof(NO));
    novo -> chave = ch;
    novo -> prox = NULL; 
    NO* p = l -> inicio;
    NO* ant = NULL;
    while (p) // p != NULL
    {
        ant = p;
        p = p -> prox;
    }
    if(ant) ant -> prox = novo; //a lista não está vazia
    else l -> inicio = novo; //anexando o primeiro elemento da lista
    
}

int main() {
    LISTA_LIG_DIN l;
    inicializar(&l); //lista vazia pronta para uso
}
