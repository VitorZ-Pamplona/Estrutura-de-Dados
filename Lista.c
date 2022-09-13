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

int main() {
}

void cria_lista(tlista *L, int tam) {
  L->dados = (int *)malloc(tam * sizeof(int));
  L->n = 0;
  L->nmax = tam;
}

int verifica_vazia(tlista *L) {
  return (L->n == 0); }

int verifica_cheia(tlista *L) {
  return (L->n == L->nmax); }

int tamanho(tlista *L) {
  return (L->n); }

int obter_elemento(tlista *L, int pos) {
  int dado;
  if ((pos < L->n) || (pos >= 0)) {
    dado = L->dados[pos - 1];
    return dado;
  } else {
    return -1;
  }
}

int obter_posicao(tlista *L, int dado) {
  for (int i = 0; i < L->n; i++) {
    if (L->dados[i] == dado) {
      return (i + 1);
    }
  }
  return -1;
}

int insere(tlista *L, int pos, int dado) {
  if (verifica_cheia(L) || (pos > L->nmax + 1) || (pos <= 0)) {
    return -1;
  }
  for (int i = L->n; i >= pos; i--) {
    L->dados[i] = L->dados[i - 1];
  }

  L->dados[pos - 1] = dado;
  L->n++;
}

int retira(tlista *L, int pos) {
  int dado;
  if ((pos > L->n) || (pos < 1)) {
    return -1;
  }

  dado = L->dados[pos - 1];
  for (int i = pos - 1; i < L->n - 1; i++) {
    L->dados[i] = L->dados[i + 1];
  }
  L->n--;
  return dado;
}

int menu() {
  int opcao;

  printf("\n         ***   MENU   ***\n");
  printf("||           Cria Lista           [1]||\n");
  printf("|| Verifica se a lista esta vazia [2]||\n");
  printf("|| Verifica se a lista esta cheia [3]||\n");
  printf("||    Verifica tamanho da Lista   [4]||\n");
  printf("||          Obter Elemento        [5]||\n");
  printf("||          Obter Posição         [6]||\n");
  printf("||         Insere Elemento        [7]||\n");
  printf("||         Retira Elemento        [8]||\n");
  printf("\nOpção: ");
  scanf("%d", &opcao);
  return opcao;
}

void opcao(tlista *lista, int op) {
  switch (op) {
    case 1:
      cria_lista(lista, int tam);
      break;
    case 2:
      verifica_vazia(lista);
      break;
    case 3:
      verifica_cheia(lista);
      break;
    case 4:
      tamanho(lista);
      break;
    case 5:
      obter_elemento(lista, int pos);
      break;
    case 6:
      obter_posicao(lista, int pos);
      break;
    case 7:
      insere(lista, pos, dado);
      break;
    case 8:
      retira(lista, int pos);
      break;
    default:
      printf("Comando Invalido\n\n");
  }
}
