#ifndef LISTASEQUENCIAL_H
#define LISTASEQUENCIAL_H

typedef struct {
    int chave;
} REGISTRO;

//estrutura de uma lista sequencial
typedef struct {
    int numElementos;
    REGISTRO A[100]; //100 é arbitrário
} LISTA_SEQ;

int tamanho(LISTA_SEQ * l);
int buscaSequencial(LISTA_SEQ * l, int ch);
void exibir(LISTA_SEQ * l);
bool anexar(LISTA_SEQ * l, int ch);
bool excluir(LISTA_SEQ * l, int ch);
void inicializa(LISTA_SEQ * l);

#endif // LISTASEQUENCIAL_H