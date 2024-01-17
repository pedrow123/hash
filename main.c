#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saida.h"

#define M 11

int main(){
    nodo_t *h1, *h2;
    h1 = criaTabela(M);
    h2 = criaTabela(M);
    
    int value;
    char in;
    in = getchar();
    
    while(in != EOF && in != 's'){
        scanf(" %d", &value);
        if(in == 'i') insere(h1, h2, value, M);
        if(in == 'r') removeElem(h1, h2, value, M);
        in = getchar();
    }
    
    imprimeSaida(h1, h2, M);

    liberaTabela(h1);
    liberaTabela(h2);
    return 0;
}