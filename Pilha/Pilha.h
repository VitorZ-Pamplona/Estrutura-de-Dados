#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int conteudo;
    struct No *prox;
}No;

typedef struct pilha{
    No *topo;
    int eElem;
}pilha;

extern void criar (pilha *e);
extern int vazia(pilha *e);
extern int tamanho (pilha *e);
extern int top (pilha *e);
extern int push(pilha *e, int valor);
extern int pop(pilha *e);
extern void menu();
