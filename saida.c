#include "saida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamHT(nodo_t* h1, nodo_t* h2, int tam){
    int counter = 0;
    for(int i = 0; i<tam; i++){
        counter += !(h1[i].disp);
        counter += !(h2[i].disp);
    }
    return counter;
}

void ordenaSaidas(saida_t* saidas, int count){
    int menor;
    for(int i = 0; i<count; i++){
        menor = i;
        for(int j = i+1; j<count; j++){
            if(saidas[menor].valor > saidas[j].valor){
                menor = j;
            }
            else if(saidas[menor].valor == saidas[j].valor){
                if(strcmp(saidas[menor].table, saidas[j].table) < 0){
                    menor = j;
                }
                else if(strcmp(saidas[menor].table, saidas[j].table) == 0){
                    if(saidas[menor].index > saidas[j].index)
                        menor = j;
                }
            }
        }
        saida_t aux = saidas[i];
        saidas[i] = saidas[menor];
        saidas[menor] = aux;
    }
}

void imprimeSaida(nodo_t* h1, nodo_t* h2, int tam){
    int tamVetor = tamHT(h1, h2, tam);
    saida_t* vetor = malloc(tamVetor * sizeof(saida_t));
    int count = 0;

    for(int i = 0; i<tam; i++){
        if(!h1[i].disp){
            vetor[count].index = i;
            vetor[count].valor = h1[i].key;
            vetor[count].table = "T1";
            count++;
        }  
        if(!h2[i].disp){
            vetor[count].index = i;
            vetor[count].valor = h2[i].key;
            vetor[count].table = "T2";
            count++;
        }  
    }
    ordenaSaidas(vetor, count);
    for(int i = 0; i<count; i++){
        printf("%d,%s,%d\n", vetor[i].valor, vetor[i].table, vetor[i].index);
    }

    free(vetor);
}