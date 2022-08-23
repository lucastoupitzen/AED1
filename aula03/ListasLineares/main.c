#include <stdio.h>
#include <stdbool.h>
#include "listaSequencial.h"

int main() {
    LISTA_SEQ l; //uma nova lista é inicializada 
    inicializa(&l);

    anexar(&l, 1); //adiciona um novo registro com chave 1 na listaSequencial
    anexar(&l, 50); 
    anexar(&l, 60);

    excluir(&l, 50);

    exibir(&l);
}