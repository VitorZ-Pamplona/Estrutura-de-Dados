#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int dado;
    struct No *esq;
    struct No *dir;
}No;

typedef struct No *raiz;

extern void cria_arvore (raiz *A);
extern int vazio (raiz A);
extern raiz buscaElemento (raiz A, int dado);
extern void lista_Conteudo (raiz A);
extern int insereElemento (raiz A, int item);
extern void menu ();