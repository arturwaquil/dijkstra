#ifndef _GRAFOS_H
#define _GRAFOS_H

#include "lista.h"
#define INFINITO 100000

void matrizAdj (int graph[][100], int numNodos, int numArestas);

void dijkstra (int graph[][100], int dist[], int origem, int opcao, int N);

int foiVisitado (int visitados[], int nodo, int limite);

void status (int dist[], int visitados[], int nodoAtual, int nodoInicial, int limite, int n);

#endif // _GRAFOS_H
