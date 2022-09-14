/****
Módulo: Lista Sequencial
Autor: Vitor Zimbrunes Pamplona
Data: 07/09/2022
Última Alteração: 07/09/2022
Descrição: Arquivo do exercicio de programação -> Lista_sequencial
****/
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

void cria_lista(tlista *L, int tam) {
    L->dados = (float *)malloc(tam * sizeof(int));
    L->n = 0;
    L->nmax = tam;
}

int verifica_vazia(tlista *L) {
    if (L->n == 0){
        return printf ("Lista vazia.\n");
    } else {
        return printf ("Lista Cheia ou invalida!\n");
    }
}

int verifica_cheia(tlista *L) {
    if (L->n == L->nmax){
        return printf ("Lista Cheia.\n");
    } else {
        return printf ("Lista com espaço.\n");
    }
}

int tamanho(tlista *L) {
    return printf ("Tamanho da lista: %i.\n", (L->n)); 
}

int obter_elemento(tlista *L, int pos) {
    int dado;
    if ((pos < L->n) || (pos >= 0)) {
        dado = L->dados[pos - 1];
        return printf ("O elemento é : %f\n" ,dado);
    } 
    else {
        return printf ("Erro ao obter o elemento!\n");
    }
}

int obter_posicao(tlista *L, float dado) {
    for (int i = 0; i < L->n; i++) {
        if (L->dados[i] == dado) {
            return printf ("A posição é %d\n" , (i + 1));
        }
    }
    return printf ("Erro ao obter a posição!\n");
}

int insere(tlista *L, int pos, float dado) {
    if (verifica_cheia(L) || (pos > L->nmax + 1) || (pos <= 0)) {
        return printf ("Erro ao Inserir o elemento!\n");
    }
    for (int i = L->n; i >= pos; i--) {
        L->dados[i] = L->dados[i - 1];
    }
    L->dados[pos - 1] = dado;
    L->n++;
    return ("Elemento inserido com sucesso!\n");
}

int retira(tlista *L, int pos) {
    int dado;
    if ((pos > L->n) || (pos < 1)) {
        return printf ("Erro ao retirar o elemento!\n");
    }
    
    dado = L->dados[pos - 1];
    for (int i = pos - 1; i < L->n - 1; i++) {
        L->dados[i] = L->dados[i + 1];
    }
    L->n--;
    return printf ("%f retirado com sucesso!\n",dado);
}

void exibir (tlista *L){
    int i;
    printf("Lista: \" ");
    for (i = 0; i < L->n; i++){
        printf("%i ", L->dados[i]);
    printf("\"\n");
    }
}


int main() {
    tlista lista;
    int tam, pos;
    float dado;
    int play = 1;

    do{
        
    }

    printf ("Decida o tamanho da Lista: "); scanf ("%d", &tam);
    cria_lista (&lista, tam);

    verifica_vazia (&lista);
    verifica_cheia (&lista);
    tamanho (&lista);

    printf ("Esolha uma posição para achar o elemento: "); scanf ("%d", &pos);
    obter_elemento (&lista, pos);

    printf ("Esolha uma elemento para achar a posição: "); scanf ("%f", &dado);
    obter_posicao (&lista, dado);

    printf ("Esolha uma posição e um elemento para adicionar a lista: "); scanf ("%d e %f", &pos, &dado);
    insere (&lista, pos, dado);

    printf ("Esolha uma posição para retirar da lista: "); scanf ("%d", &pos);
    retira (&lista, pos);
    exibir (&lista);
}
