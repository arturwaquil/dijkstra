#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

/* matrizAdj:
    Imprime na tela a matriz de adjacencia de um grafo, recebida como parametro. */
void matrizAdj (int graph[][100], int numNodos, int numArestas)
{
    int i, j;

    printf("\n     |");
    for (j = 0; j < numNodos; j++)          ///imprime a primeira linha, com os indices das colunas
    {
        if (j < 10)
            printf("**%d**|", j);           ///ajusta a formatacao de acordo com o numero de digitos
        else
            printf("*%d**|", j);
    }

    printf("\n------");
    for (j = 0; j < numNodos; j++)          ///imprime linha de "-"
        printf("------");
    printf("\n");

    for (i = 0; i < numNodos; i++)          ///para cada linha da matriz
    {
        if (i < 10)
            printf("**%d**|", i);           ///imprime o indice da linha, formatando de acordo com o numero de digitos
        else
            printf("*%d**|", i);

        for (j = 0; j < numNodos;  j++)     ///para cada coluna da linha da matriz
            printf("%3d  |", graph[i][j]);

        printf("\n------");
        for (j = 0; j < numNodos; j++)      ///imprime linha de "-"
            printf("------");
        printf("\n");
    }
}

/* dijkstra:
    Executa o algoritmo de busca de Dijkstra para preencher a tabela de distancias a partir de um nodo de origem. */
void dijkstra (int graph[][100], int dist[], int origem, int opcao, int numNodos)
{
    Lista *lista_nodos;
    int visitados[numNodos],
        i, j,
        nodo,
        menorDist;

    lista_nodos = NULL;
    for (i = 0; i < numNodos; i++)
    {
        if (i == origem)
            dist[i] = 0;                    ///inicializa a tabela de distancias (lista de prioridade)
        else                                ///com INFINITO, exceto o nodo de origem
            dist[i] = INFINITO;

        visitados[i] = INFINITO;                        ///inicializa todas as posicoes do array de visitados com INFINITO
        lista_nodos = insereLista(lista_nodos, i);      ///insere todos os nodos na lista
    }

    i = 0;
    while (!ehVazia(lista_nodos))
    {
        menorDist = INFINITO + 1;

        ///encontra o nodo ainda nao visitado que tem a menor distancia desde o nodo inicial
        for (j = 0; j < numNodos; j++)
        {
            if (dist[j] < menorDist && !foiVisitado(visitados, j, i))
            {
                menorDist = dist[j];
                nodo = j;
            }
        }

        lista_nodos = retiraLista(lista_nodos, nodo);   ///retira o nodo da lista e
        visitados[i] = nodo;                            ///o marca como visitado

        for (j = 0; j < numNodos; j++)
        {
            ///se ha aresta entre nodo e j e a distancia ate j passando por nodo eh menor que dist[j], atualiza esse valor
            if (graph[nodo][j] != 0 && dist[j] > dist[nodo] + graph[nodo][j])
                dist[j] = dist[nodo] + graph[nodo][j];
        }

        if (opcao != 0)
            status(dist, visitados, nodo, origem, i, numNodos);

        i++;
    }
}

/* foiVisitado:
    Verifica se o nodo recebido como parametro esta marcado como visitado no array, ate uma dada posicao; retorna 1 se estiver e 0 caso contrario. */
int foiVisitado (int visitados[], int nodo, int limite)
{
    int i;

    for (i = 0; i <= limite; i++)
    {
        if(visitados[i] == nodo)
            return 1;
    }

    return 0;
}

/* status:
    Eh a funcao que exibe as informacoes quando pedida a execucao passo a passo. */
void status (int dist[], int visitados[], int nodoAtual, int nodoInicial, int limite, int numNodos)
{
    int i;

    printf("\nNodo atual: %d", nodoAtual);
    printf("\nDistancia de %d: %d", nodoInicial, dist[nodoAtual]);

    printf("\nNodos visitados: ");
    for (i = 0; i <= limite; i++)
        printf("%d ", visitados[i]);

    printf("\nDistancias:\n");
    for (i = 0; i < numNodos; i++)
        printf("  de %d ate %d = %d\n", nodoInicial, i, dist[i]);
}
