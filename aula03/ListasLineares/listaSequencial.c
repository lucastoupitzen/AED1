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
        // recua os elementos a partir do excluido em uma posição
        l -> A[i].chave = l -> A[i + 1].chave;
    }

    l -> numElementos--;
    return(true);
}

int buscaBinaria(LISTA_SEQ * l, int ch) { //quando a lista está ordenada e sem espaços em branco

/*A Ideia é buscar os elementos a partir do elemento central, ajustando a busca para a metade menor ou metade maior de acordo com o valor obtido na busca central.

É a maneira mais eficiente de se tratar uma busca em listas sequenciais grandes de dados
*/

    int inf = 0;
    int sup = l -> numElementos - 1;

    while(inf <= sup) {

        int meio = (sup + inf) / 2;

        if (l -> A[meio].chave == ch){
            return(meio);
        } else if(l -> A[meio].chave < ch) {
            sup = meio - 1;
        } else {
            inf = meio + 1;
        }
    } 

    return(-1); //não encontrou o elemento
}

/*A atualização de dados em listas sequenciais é muito custosa, pois até todos os elementos podem ter que ser movimentados ou para direita ou para esquerda, sendo então um problema característico desse tipo de lista.*/