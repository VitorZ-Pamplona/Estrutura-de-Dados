/****
Módulo: Árvores Binárias de Busca
Autor: Vitor Zimbrunes Pamplona
Data: 01/11/2022
Última Alteração: 03/11/2022
Descrição: Arquivo do exercicio de programação -> AvBB
****/
#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

void cria_arvore (raiz *A){
    *A = malloc(sizeof(No));
    *A = NULL;
}

int vazio (raiz A){
    if (A == NULL){
        return -1;
    };
}

extern raiz buscaElemento (raiz A, int dado){
    if (A == NULL){
        return NULL;
    }
    if (A->dado == dado){
        return A;
    }
    if (A->dado > dado){
        return buscaElemento(A->esq, dado);
    } else {
        return buscaElemento(A->dir, dado);
    }
}

extern void lista_Conteudo (raiz A){
    if (A != NULL){
        lista_Conteudo (A->esq);
        printf("%d ", A->dado);
        lista_Conteudo (A->dir);
    }
}

extern int insereElemento (raiz A, int item){
    No *novoNo, *atual, *p;
    novoNo = malloc(sizeof(No));

    if (novoNo == NULL){
        return 0;
    }

    novoNo->dado = item;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    if (A == NULL){
        A = novoNo;
        return 1;
    }
    atual = A;
    while (atual != NULL){
        p = atual;
        } 
        if (atual->dado > item){
            atual = atual->esq;
        } else{
            atual = atual->dir;
    }

    if (p->dado > item){
        p->esq = novoNo;
    } else{
        p->dir = novoNo;
    }
    return 1;
}

void menu(){
    printf("\n\n      ## Menu ##\n\n");
    printf("1.   Criar Árvore\n");
    printf("2. Verificar se Vazia\n");
    printf("3.  Buscar Elemento\n");
    printf("4.  Listar Conteudo\n");
    printf("5.     Inserir\n");
    printf("0.      Sair\n");
}

int main() {
    raiz A;
    int dado;
    int op = 1;

    do{
        menu ();
        scanf("%d", &op);

        switch (op){
            case 1:
                cria_arvore (&A);
                break;
            case 2:
                if (vazio(A) == -1){
                    printf ("\nA Árvore está Vazia!");
                } else{
                    printf ("\nA Árvore não está Vazia!");
                };
                break;
            case 3:
                printf ("\nEsolha um elemento para achar: "); scanf ("%d", &dado);
                buscaElemento (A, dado);
                break;
            case 4:
                lista_Conteudo (A);
                break;
            case 5:
                printf ("\nEsolha um elemento para adicionar a Árvore: "); 
                scanf ("%d", &dado);
                insereElemento (A, dado);
                break;
            case 0:
                op = 0;
                break;
            default:
                printf("\nOpção Invalida\n");
        }
    } while (op);
}
