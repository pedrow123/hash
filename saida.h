#include "hash.h"

struct saida{
    int valor;
    char* table;
    int index;
};
typedef struct saida saida_t;

void imprimeSaida(nodo_t* h1, nodo_t* h2, int tam);