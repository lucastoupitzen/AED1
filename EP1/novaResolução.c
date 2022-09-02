#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>


// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("11804164");
}


// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Lucas Toupitzen Ferracin Garcia");
}

// elemento da lista
typedef struct estr {
        int valor;
        struct estr* prox;
} NO;

// funcao principal
NO* uniao(NO* p1, NO* p2);

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------

void exibir(NO* p) {
	while(p != NULL) {
		printf("Elemento da lista -> %i\n", p -> valor);
		p = p -> prox;
	}
}

NO* buscar(NO* pInicial, int valorBuscado, NO ** ant) {
    //retornar NULL se o elemento for novo e retornar um nó arbitrário apenas para apontar que é repetido
    NO* controle = pInicial;
    *ant = NULL;
    while (controle) // controle != NULL
    {
        if(controle -> valor > valorBuscado){
            return(NULL);
        } else if(controle -> valor == valorBuscado){
            return(controle);
        } else {
            *ant = controle;
            controle = controle -> prox;
        }
    }
    //cheguei ao final da lista
    return(NULL);
    
}

bool inserir(NO** pInicial, int valorInserido) {

    NO* novo;
    NO* ant;
    novo = buscar(*pInicial, valorInserido, &ant);
    if(novo) return(false); //o elemento já está na lista
    //tratar o caso em que anterior é nulo
    novo = (NO*) malloc(sizeof(NO));
    novo -> valor = valorInserido;
    if(!*pInicial) { // a lista está vazia
        *pInicial  = novo;
        novo -> prox = NULL;
    } 
    else {
        if(!ant) { //primeira posição da lista
            novo -> prox = *pInicial;
            *pInicial = novo;
        } 
        else {
            novo -> prox = ant -> prox;
            ant -> prox = novo;
        }
        
    }
    return(true);
}



NO* uniao(NO* p1, NO* p2) {

	NO* resp = NULL;

	// seu codigo AQUI
    while(p1 != NULL) {
        inserir(&resp, p1 -> valor);
        p1 = p1 -> prox;
    }

    while(p2 != NULL) {
        inserir(&resp, p2 -> valor);
        p2 = p2 -> prox;
    }

	return resp;
}





//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {

	NO* p1 = NULL;
	NO* p2 = NULL;

	// aqui vc pode incluir codigo para inserir elementos
	// de teste nas listas p1 e p2

    //lista teste 1
    inserir(&p1, 10);
    inserir(&p1, 9);
    inserir(&p1, 12);
    inserir(&p1, 13);
    // p1 -> valor = 10;   
    // NO* p11 = (NO*) malloc(sizeof(NO*));
    // p1 -> prox = p11;

    // p11 -> valor = 11;
    // NO* p12 = (NO*) malloc(sizeof(NO*));
    // p11 -> prox = p12;

    // p12 -> valor = 12;
    // NO* p13 = (NO*) malloc(sizeof(NO*));
    // p12 -> prox = p13;

    // p13 -> valor = 13;
    // NO* p14 = (NO*) malloc(sizeof(NO*));
    // p13 -> prox = p14;

    // p14 -> valor = 14;
    // p14 -> prox = NULL;
    
	//lista teste 2
    inserir(&p2, 13);
    inserir(&p2, 21);
    inserir(&p2, 22);
    inserir(&p2, 23);

    // p2 -> valor = 20;
    // NO* p21 = (NO*) malloc(sizeof(NO*));
    // p2 -> prox = p21;

    // p21 -> valor = 21;
    // NO* p22 = (NO*) malloc(sizeof(NO*));
    // p21 -> prox = p22;

    // p22 -> valor = 22;
    // NO* p23 = (NO*) malloc(sizeof(NO*));
    // p22 -> prox = p23;

    // p23 -> valor = 23;
    // NO* p24 = (NO*) malloc(sizeof(NO*));
    // p23 -> prox = p24;

    // p24 -> valor = 24;
    // p24 -> prox = NULL;

	// o EP sera testado com chamadas deste tipo
	NO* teste = NULL;
    
	teste = uniao(p1,p2);
    exibir(teste);

}

// por favor nao inclua nenhum código abaixo deste ponto