#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int dado;
    struct No *prox;
}No;

typedef struct tlista{
    No *cabeca;
    int tam;
}tlista;

int tam = 0;
tlista *cabeca = NULL;

extern void cria_lista (tlista *lista);
extern int verifica_vazia (tlista *lista);
extern int tamanho (tlista *lista);
extern int obter_elemento (tlista *lista, int pos);
extern int insere (tlista *lista, int pos , int dado);
extern int insere_inicio (tlista *lista, int dado);
extern int insere_fim (tlista *lista, int dado);
extern int insere_meio (tlista *lista, int pos , int dado);
extern int retira (tlista *lista, int pos);
extern int retira_inicio (tlista *lista, int pos);
extern int retira_dalista (tlista *lista, int pos);
extern void exibir (tlista *lista);
extern void menu ();