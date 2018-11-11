#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* insereLista:
    Insere um nodo no final duma lista duplamente encadeada. Se esta for vazia, insere o primeiro elemento. */
Lista* insereLista (Lista* inicio, int valor)
{
    Lista *aux, *novo;

    novo = (Lista*)malloc(sizeof(Lista));   ///aloca memoria para o novo nodo

    if (inicio == NULL)
    {
        ///insere o novo nodo sozinho na lista
        novo->nodo = valor;
        novo->prox = NULL;
        novo->ant = NULL;
        inicio = novo;
    }
    else
    {
        aux = inicio;

        ///encontra o ultimo elemento da lista para inserir o novo nodo ao final desta
        while (aux->prox != NULL)
            aux = aux->prox;

        novo->nodo = valor;
        novo->prox = NULL;
        novo->ant = aux;
        aux->prox = novo;
    }

    return inicio;
}

/* retiraLista:
    Retira um nodo de uma lista duplamente encadeada. Se for o unico elemento desta, esvazia-a. */
Lista* retiraLista (Lista* inicio, int valor)
{
    Lista *aux;

    aux = inicio;

    ///encontra o nodo a ser excluido da lista
    while (aux->nodo != valor)
        aux = aux->prox;

    if (aux->ant == NULL)
    {
        if(aux->prox == NULL)   ///se aux for o unico elemento da lista
        {
            free(aux);
            inicio = NULL;
        }
        else                    ///se aux for o primeiro mas nao unico elemento da lista
        {
            inicio = aux->prox;
            aux->prox->ant = NULL;

            free(aux);
        }
    }
    else if (aux->prox == NULL) ///se aux for o ultimo elemento da lista
    {
        aux->ant->prox = NULL;

        free(aux);
    }
    else                        ///se aux for um elemento no meio da lista
    {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;

        free(aux);
    }

    return inicio;
}

/* ehVazia:
    Verifica se uma lista eh vazia; retorna 1 se o for e 0 caso contrario. */
int ehVazia (Lista* inicio)
{
    if (inicio == NULL)
        return 1;
    else
        return 0;
}
