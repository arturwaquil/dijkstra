/// Trabalho final de Teoria dos Grafos (INF05512) - 2017/2
/// Professor Tadeu Zubaran
///
/// Alunos:
///   Artur Waquil Campana
///   Julia Peixoto Violato
///   Nicolas Casagrande Duranti
///
/// Este trabalho eh uma implementacao do algoritmo de busca de Dijkstra para um grafo simples valorado

#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#include "lista.h"

int main ()
{
    FILE *arq;
    char nomeArq[30];
    int i, numNodos, numArestas,
        n1, n2, peso,
        grafo[100][100] = {{0}},
        imprimir;

    puts("  _____   _  _  _          _                ");
    puts(" |  __ \\ (_)(_)| |        | |               ");
    puts(" | |  | | _  _ | | __ ___ | |_  _ __  __ _  ");
    puts(" | |  | || || || |/ // __|| __|| '__// _` | ");
    puts(" | |__| || || ||   < \\__ \\| |_ | |  ( (_| | ");
    puts(" |_____/ |_|| ||_|\\_\\/___/ \\__||_|   \\__,_| ");
    puts("           _/ |                             ");
    puts("          |__/                              ");

    do  ///recebe o nome do arquivo e o abre
    {
        printf("\n");
        printf("Nome do arquivo (incluindo a extensao): ");
        scanf("%s", nomeArq);

        arq = fopen(nomeArq, "r");

        if (arq == NULL)
            printf("Erro ao abrir arquivo: %s\n", nomeArq);

    }
    while (arq == NULL);

    fscanf (arq, "%d %d", &numNodos, &numArestas);  ///le do arquivo os numeros de nodos e de arestas

    for (i = 0; i <= numArestas; i++)
    {
        fscanf (arq, "%d %d %d", &n1, &n2, &peso);  ///para cada aresta, le os nodos adjacentes a ela e o seu peso
        grafo[n1][n2] = peso;
        grafo[n2][n1] = peso;                       ///preenche a matriz de adjacencia do grafo
    }

    fclose(arq);

    printf("\nImprimir a matriz de adjacencia do grafo? (0 - nao / 1 - sim)\n");
    scanf("%d", &imprimir);

    if (imprimir)
        matrizAdj(grafo, numNodos, numArestas);         ///imprime a matriz de adjacencia se for pedido

    int origem, destino,
        dist[numNodos],
        op;

    printf("\nNodo origem? ");
    scanf("%d", &origem);
    printf("\nNodo destino? ");
    scanf("%d", &destino);

    printf("\nExibir algoritmo passo a passo? (0 - nao / 1 - sim)\n");
    scanf("%d", &op);

    dijkstra(grafo, dist, origem, op, numNodos);    ///executa o algoritmo - dist[] eh alterada

    printf("\nMenor caminho entre %d e %d: %d\n\n", origem, destino, dist[destino]);

    return 0;
}
