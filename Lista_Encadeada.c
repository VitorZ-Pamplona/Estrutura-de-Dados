/****
Módulo: Lista Encadeada
Autor: Vitor Zimbrunes Pamplona
Data: 16/09/2022
Última Alteração: 22/09/2022
Descrição: Arquivo do exercicio de programação -> Lista_Encadeada
Consertar a função obter_elemento e Exibir!
****/
#include "Lista_Encadeada.h"
#include <stdio.h>
#include <stdlib.h>

void cria_lista (tlista *L){
    L->cabeca = (No*) malloc(sizeof(No));
    L->tam = 0;
    L->cabeca = NULL;
}

int verifica_vazia (tlista *L){
    if (L->tam == 0){
        return -1;
    } else{
    return 1;
    }
}

int obter_elemento (tlista *L, int pos){
    if (verifica_vazia(L) == -1){
        return printf ("Lista sem elementos.");
    }
    if ((pos < 1) || (pos > L->tam)){
        return printf ("\nPosição Invalida.\n");
    }else {
    No *aux = L->cabeca;
    int cont = 1;
    while (cont < pos){
        aux = aux->prox;
        cont++;
    }
    return printf ("O elemento é : %d",aux->dado);
    }
}

int tamanho (tlista *L){
    return printf ("\nTamanho é %d.\n", L->tam);
}

int insere (tlista *L, int pos, int dado){
    if (verifica_vazia(L) == -1 && pos != 1){
        printf ("Posição Invalida!");
        return -1;
    }
    if (pos == 1){
        return insere_inicio(L, dado);
    }
    if (pos == L->tam +1){
        return insere_fim(L, dado);
    }
    else {
        return insere_meio(L, pos, dado);
    }
}

int insere_inicio (tlista *L, int dado){

    No *p = (No*) malloc(sizeof(No));
    p->dado = dado;
    p->prox = L->cabeca;
    L->cabeca = p;
    L->tam++;

    printf ("\nElemento inserido no Inicio com sucesso!\n");
    return 1;
}

int insere_fim (tlista *L, int dado){
    No *p = (No*) malloc(sizeof(No));
    p->dado = dado;

    No *aux = L->cabeca;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    p->prox = NULL;
    aux->prox = p;
    L->tam++;
    printf ("\nInserido no Final com sucesso!\n");
    return 1;
}

int insere_meio (tlista *L, int pos, int dado){
    int cont = 1;
    No *p = (No*) malloc(sizeof(No));
    p->dado = dado;

    No *aux = L->cabeca;
    while ((cont < pos-1)  && (aux != NULL)){
        aux = aux->prox;
        cont++;
    }
    if (aux == NULL){
        printf ("\nErro na inserção.\n");
        return -1;
    } 

    p->prox = aux->prox;
    aux->prox = p;
    L->tam++;
    printf ("\nInserido na posição com sucesso!\n");
    return 1;
}

int retira (tlista *L, int pos){
    if (verifica_vazia(L) == -1){
        return verifica_vazia(L);
    }
    if (pos == 1){
        return retira_inicio(L, pos);
    }else {
        return retira_dalista(L, pos);
    }

}

int retira_inicio (tlista *L, int pos){
    No *aux = L->cabeca;
    int d = aux->dado;
    L->cabeca = aux->prox;
    L->tam--;
    free(aux);
    return printf ("\nO elemento: %d foi removido!\n", d);
}

int retira_dalista (tlista *L, int pos){
    No *atual = NULL, *ant = NULL;
    int dado = -1, cont = 1;

    atual = L->cabeca;
    while((cont < pos) && (atual != NULL)){
        ant = atual;
        atual = atual->prox;
        cont++;
    }
    if (atual == NULL){
        return -1;
    }
    dado = atual->dado;
    ant->prox = atual->prox;
    L->tam--;

    free(atual);
    return printf ("Elemento : %d retirado!", dado);
}

void exibir (tlista *L){
    No *p;
    p = L->cabeca;
    printf ("\nValores da Lista: \n");
    while (p != NULL){
        printf (" -> %d", p->dado);
        p = p->prox;
    }
    printf ("\n");
}

void menu(){
    printf("\n\n      ## Menu ##\n\n");
    printf(" 1.   Criar Lista\n");
    printf(" 2. Verificar se Vazia\n");
    printf(" 3. Tamanho da Lista\n");
    printf(" 4.  Obter Elemento\n");
    printf(" 5.     Inserir\n");
    printf(" 6.     Retirar\n");
    printf(" 7.     Exibir\n");
    printf(" 0.      Sair\n");
}

int main() {
    tlista lista;
    int pos, dado;
    int op = 1;

    do{
        menu ();
        scanf("%d", &op);

        switch (op){
            case 1:
                cria_lista (&lista);
                break;
            case 2:
                if (verifica_vazia(&lista) == -1){
                    printf ("\nA lista esta Vazia!");
                } else{
                    printf ("\nA lista não está Vazia!");
                };
                break;
            case 3:
                tamanho (&lista);
                break;
            case 4:
                printf ("\nEsolha uma posição para achar o elemento: "); scanf ("%d", &pos);
                obter_elemento (&lista, pos);
                break;
            case 5:
                printf ("\nEsolha uma posição e um elemento para adicionar a lista: "); 
                scanf ("%d %f", &pos, &dado);
                insere (&lista, pos, dado);
                break;
            case 6:
                printf ("\nEsolha uma posição para retirar da lista: "); scanf ("%d", &pos);
                retira (&lista, pos);
                break;
            case 7:
                exibir (&lista);
                break;
            case 0:
                op = 0;
                break;
            default:
                printf("\nOpção Invalida\n");
        }
    } while (op);
}
