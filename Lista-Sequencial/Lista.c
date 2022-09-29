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
    L->dados = (int *)malloc(tam * sizeof(int));
    L->n = 0;
    L->nmax = tam;
}

int verifica_vazia(tlista *L) {
    if (L->n == 0){
        return printf ("Lista vazia.\n");
    } else {
        return printf ("Lista com valores!\n");
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

int obter_posicao(tlista *L, int dado) {
    for (int i = 0; i < L->n; i++) {
        if (L->dados[i] == dado) {
            return printf ("A posição é %d\n" , (i + 1));
        }
    }
    return printf ("Erro ao obter a posição!\n");
}

int insere(tlista *L, int pos, int dado) {
    if (L->n == L->nmax || (pos > L->nmax + 1) || (pos <= 0)) {
        return printf ("Erro ao Inserir o elemento!\n");
    }
    for (int i = L->n; i >= pos; i--) {
        L->dados[i] = L->dados[i - 1];
    }
    L->dados[pos - 1] = dado;
    L->n++;
    return printf ("Elemento inserido com sucesso!\n");
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

void menu(){
    printf("\n     ## Menu ##\n\n");
    printf(" 1.   Criar Lista\n");
    printf(" 2. Verificar se Vazia\n");
    printf(" 3. Verificar se Cheia\n");
    printf(" 4.  Tamanho da Lista\n");
    printf(" 5.  Obter Elemento\n");
    printf(" 6.   Obter Posição\n");
    printf(" 7.    Inserir\n");
    printf(" 8.    Retirar\n");
    printf(" 9.    Exibir\n");
    printf(" 0.    Sair\n");
}

int main() {
    tlista lista;
    int tam, pos;
    float dado;
    int op = 1;

    do{
        menu ();
        scanf("%d", &op);

        switch (op){
            case 1:
                printf ("Decida o tamanho da Lista: "); scanf ("%d", &tam);
                cria_lista (&lista, tam);
                break;
            case 2:
                verifica_vazia (&lista);
                break;
            case 3:
                verifica_cheia (&lista);
                break;
            case 4:
                tamanho (&lista);
                break;
            case 5:
                printf ("Esolha uma posição para achar o elemento: "); scanf ("%d", &pos);
                obter_elemento (&lista, pos);
                break;
            case 6:
                printf ("Esolha uma elemento para achar a posição: "); scanf ("%f", &dado);
                obter_posicao (&lista, dado);
                break;

            case 7:
                printf ("Esolha uma posição e um elemento para adicionar a lista: "); 
                scanf ("%d %f", &pos, &dado);
                insere (&lista, pos, dado);
                break;
            case 8:
                printf ("Esolha uma posição para retirar da lista: "); scanf ("%d", &pos);
                retira (&lista, pos);
                break;
            case 9:
                exibir (&lista);
                break;
            case 0:
                op = 0;
                break;
            default:
                printf("Opção Invalida\n");
        }
    } while (op);
    free (&lista);
}
