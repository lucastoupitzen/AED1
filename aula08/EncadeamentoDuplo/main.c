#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s{
    struct s *prox;
    struct s *ant; //novo ponteiro apontando para o item anterior
    int chave; 
} NO; //NÓ duplo

/*lista com encadeamento duplo, cabeça e circularidade */

typedef struct {
    NO* cabeça;
} LISTA_DUPLA_CAB_CIRC;

void inicializar(LISTA_DUPLA_CAB_CIRC * l) {
    l -> cabeça = (NO*) malloc(sizeof(NO));
    l -> cabeça -> prox = l -> cabeça; //circularidade
    l -> cabeça -> ant = l -> cabeça;
}

//exibir a lista em ordem inversa
void exibirInversa(LISTA_DUPLA_CAB_CIRC * l) {
    NO* p = l -> cabeça -> ant;
    while(p != l -> cabeça) {
        printf("%d", p -> chave);
        p = p -> ant;
    }
}

bool excluir(LISTA_DUPLA_CAB_CIRC * l, int ch) {
    NO* anterior;
    NO* atual = busca(l, ch, &anterior);
    if(!atual) return(false);
    anterior -> prox = atual -> prox;
    atual -> prox -> ant = anterior;
    free(atual);
    return(true);
}

bool inserir(LISTA_DUPLA_CAB_CIRC * l, int ch) {
    NO* anterior;
    NO* atual = busca(l , ch, &anterior);
    if(atual) return(false); //já existe
    NO* novo = (NO*) malloc(sizeof(NO));
    novo -> chave = ch;
    //cuidado com as referências
    novo -> ant = anterior;
    novo -> prox = anterior -> prox;
    anterior -> prox = novo;
    novo -> prox -> ant = novo;
    
}