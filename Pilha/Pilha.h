#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int topo;
    int limite;
    float *eElem;
}pilha;

extern void criar (pilha *e, int l);
extern int vazia(pilha *e);
extern int cheia(pilha *e);
extern void adicionar(pilha *e, float valor);
extern float retira(pilha *e);
extern void limpar(pilha *e);
extern void menu();
