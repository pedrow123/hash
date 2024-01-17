#include <stdlib.h>
#include <math.h>
#include "hash.h"

nodo_t* criaTabela(int tam){
    nodo_t* table = malloc(tam * sizeof(nodo_t));
    for(int i = 0; i<tam; i++){
        table[i].key = -1;
        table[i].disp = true;
    }
    return table;
}

int liberaTabela(nodo_t* table){
    free(table);
    return 1;
}

int insere_2(nodo_t* tableP, nodo_t* tableS, int value, int tam, int index1){
    int index2 = floor(tam * (0.9 * tableP[index1].key - floor(0.9 * tableP[index1].key)));
    tableS[index2].key = tableP[index1].key;
    tableS[index2].disp = false;

    tableP[index1].key = value;

    return index2;    
}

int insere(nodo_t* tableP, nodo_t* tableS, int value, int tam){
    int index = value % tam;
    if(tableP[index].key == value && !tableP[index].disp)
        return -1;
    if(tableP[index].disp){
        tableP[index].key = value;
        tableP[index].disp = false;
        return -1;
    }

    return insere_2(tableP, tableS, value, tam, index);
}

int removeElem(nodo_t* tableP, nodo_t* tableS, int value, int tam){
    int index1 = value % tam;
    int index2 = floor(tam * (0.9 * value - floor(0.9 * value)));

    if(tableS[index2].key == value){
        tableS[index2].disp = true;
        return index2;
    }

    if(tableP[index1].key == value){
        tableP[index1].disp = true;
        return index1;
    }

    return -1;
}