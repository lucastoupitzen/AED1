#include <stdio.h>
#include <stdbool.h>

/* 

Não há a necessidade de que a ordem física dos elementos na memória seja a mesma da ordem lógica

São necessárias ligações que levem de um elemento ao próximo e a passagem do índice do elemento que será o primeiro a ser consultado

Como lidar com as posições vazias -> Ter uma lista "fantasma" que guarda as posições disponíveis (alocação estática de memória)

ex: início -> 10 -> 20 -> 30 -> 40 -> 50 -> saída... (cada -> é uma indicação leva ao próximo elemento)

*/

// estrutura de um registro de lista ligada

const int max = 100;

typedef struct {
    int chave;
    int proximo; 
} REGISTRO;

//estrutura de uma lista ligada

typedef struct {
    int inicio;
    int disponivel; //indicador de inicio da lista de disponíveis
    REGISTRO A[max]; //max é arbitrário
} LISTA_LIG_EST; // = lista ligada estaticamente

void inicializar(LISTA_LIG_EST * l) {

    l -> inicio = -1; //indice inválido -> indica lista vazia
    l -> disponivel = 0; 
    //qualquer valor seria válido, já que todos as casas da lista estão disponíveis 
    int i;
    for(i = 0; i < max - 1; i++) { //indexa todos os registros com o índice do próximo registro
        l -> A[i].proximo = i + 1;
    }
    l -> A[max - 1].proximo = -1; // a última posição indica que acabou

}

void exibir(LISTA_LIG_EST * l) { //exibe todas as chaves que existem

    int i = l -> inicio;

    while(i != -1) { // se a lista for vazia, inicio já vale -1
        printf("%d", l -> A[i].chave);
        i = l -> A[i].proximo; //passa para o próximo elemento indexado àquela chave analizada
    }
}


int busca(LISTA_LIG_EST * l, int ch, int * anterior) { 
    //anterior será o endereço da memória que poderá ser acessado na main -> passado por referência
    //Será necessário para inserção
    *anterior = -1; //não há elemento anterior ao inicial
    int i = l -> inicio;
    while(i != -1) {
        if( l -> A[i].chave >= ch) break;
        *anterior = i;
        i = l -> A[i].proximo;
    }
    if(l -> A[i].chave == ch) return(i);
    return(-1); //não achou a chave
}

int main() {

    LISTA_LIG_EST l;
    inicializar(&l);

    int anterior;
    int x = 25;
    int posicao = busca(&l, x, &anterior);
    if(posicao != -1) {
        printf("%i\n", posicao);
    } 

}