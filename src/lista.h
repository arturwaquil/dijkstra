#ifndef _LISTA_H
#define _LISTA_H

typedef struct nodo Lista;

/* define uma lista duplamente encadeada */
struct nodo
{
    int nodo;
    Lista *prox;
    Lista *ant;
};

Lista* insereLista (Lista* inicio, int valor);

Lista* retiraLista (Lista* inicio, int valor);

int ehVazia (Lista* inicio);

#endif // _LISTA_H
