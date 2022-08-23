#include <stdbool.h>
#include <stdio.h>

/* É o tipo de lista que a ordem lógica dos elementos da lista coincidem 
com a ordem física(memória)

Não há espaço em branco entre os elementos(buraco)

Segue um exemplo de implementação de uma lista sequencial de registros */

// estrutura de um registro
typedef struct {
    int chave;
} REGISTRO;

//estrutura de uma lista sequencial
typedef struct {
    int numElementos;
    REGISTRO A[100]; //100 é arbitrário
} LISTA_SEQ;


void inicializa(LISTA_SEQ * l){
    //define o número de elementos que inicializa a lista l
    l -> numElementos = 0; //define qual é a posição vazia que será utilizada depois
}

bool anexar(LISTA_SEQ * l, int ch) // ch é uma nova chave que irá ser incluída
{
    if(l -> numElementos == 100) return(false);//vetor está na última posição
    l -> A[l -> numElementos].chave = ch; // registra a chave na posição controlada por numElementos
    l -> numElementos++;
    return(true);
}

void exibir(LISTA_SEQ * l) {
    for(int i = 0; i < l -> numElementos; i++) {
        //printa o numero do registro e a chave registrada
        printf("Registro %i chave %d\n", i, l -> A[i].chave); 
    }
}

int tamanho(LISTA_SEQ * l) {
    return( l -> numElementos);
}

int buscaSequencial(LISTA_SEQ * l, int ch) { //busca o registro com a chave ch na lista l
    //retorna o índice ou -1(não achou)
    for(int i = 0; i < l -> numElementos; i++){
        if(l -> A[i].chave == ch) {
            return(i);
        }
        if(l -> A[i].chave > ch) return(-1);
        /*caso a lista esteja ordenada em ordem crescente, quebra o laço prematuramente
        em caso da chave do registro ser maior que a chave passada */
    }
    return(-1);
}

bool excluir(LISTA_SEQ * l, int ch) { //exclui o registro com a chave ch passada

    int pos = buscaSequencial(l, ch); // l não deve receber & pois já é um ponteiro
    if(pos == -1) {
        return(false); //não encontrou o elemento
    }

    for(int i = pos; i < (l -> numElementos) - 1; i++) { 
        // recua os elementos a partir do excluidoem uma posição
        l -> A[i].chave = l -> A[i + 1].chave;
    }

    l -> numElementos--;
    return(true);
}