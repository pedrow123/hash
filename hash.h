#include <stdio.h>
#include <stdbool.h>

struct nodo {
    bool disp;
    int key;
};
typedef struct nodo nodo_t;

nodo_t* criaTabela();
int liberaTabela();

int insere(nodo_t* tableP, nodo_t* tableS, int value, int tam);
int removeElem(nodo_t* tableP, nodo_t* tableS, int value, int tam);