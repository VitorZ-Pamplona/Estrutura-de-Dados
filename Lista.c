/****

Módulo: Lista Sequencial
Autor: Vitor Zimbrunes Pamplona
Data: 07/09/2022
Última Alteração: 07/09/2022
Descrição: Arquivo do exercicio de programação -> Lista_sequencial

****/
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void cria_lista (tlista *L){
    L -> n = 0 ;
    L->nmax = 100;
}

int verifica_vazia (tlista L){
    return (L.n == 0);
}

int verifica_cheia (tlista L){
    return (L.n == L.nmax);
}

int tamanho (tlista L){
    return (L.n);
}

int obter_elemento (tlista *L, int pos){
    int dado;
    if ((pos < L->n) || (pos >= 0)){
        dado = L->dados[pos-1];
        return dado;
    }
}

extern int obter_posicao (tlista *L, int dado){
    for (int i = 0; i < L->n ; i++){
        if (L -> dados[i] == dado){
            return (i + 1);
        }
    }
    return -1;
}

int insere (tlista *L, int pos, int dado){
    if (verifica_cheia(*L) || (pos > L->nmax + 1) || (pos <= 0)){
        return -1;
    }
    for (int i = L->n; i >= pos; i--){
        L->dados[i] = L->dados[i-1];
    }

    L->dados[pos - 1] = dado;
    L->n++;
}

int retira (tlista *L, int pos){
    int dado;
    if ((pos > L->n) || (pos < 1)){
        return -1;
    }
    dado = L->dados[pos-1];
    for (int i = pos - 1; i < L->n - 1; i++){
        L->dados[i] = L->dados[i+1];
    }
    L->n--;
    return dado;
}

int main(){

    cria_lista(Lista);
}