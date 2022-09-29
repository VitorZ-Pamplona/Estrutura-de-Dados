#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void criar(pilha *e){ 
    e->topo = (No*) malloc(sizeof(No));
    e->topo = NULL;
    e->eElem = 0;
}

int vazia(pilha *e){ 
    if(e->eElem == 0){
        return -1;
    }
    return 0;
}

int tamanho(pilha *e){
    return e->eElem;
}

int top(pilha *e){
    return e->topo->conteudo;
}

int push(pilha *e, int valor){ 
    No *p = (No*) malloc(sizeof(No));
    p->conteudo = valor;
    p->prox = e->topo;
    e->topo = p;
    e->eElem++;
    return valor;
}

int pop(struct pilha *e){
    No *p = e->topo;
    int valor = p->conteudo;

    e->topo = p->prox;
    e->eElem--;

    free(p);
    return valor;
}

void menu(){
    printf("\n|           MENU              |\n");
    printf("|       Criar pilha       [1] |\n");
    printf("|  Testar se pilha vazia  [2] |\n");
    printf("|     Tamanho da pilha    [3] |\n");
    printf("|  Top (Consultar o topo) [4] |\n");
    printf("|     Push (empilhar)     [5] |\n");
    printf("|    Pop (desempilhar)    [6] |\n");
    printf("|           Sair          [0] |\n");
    printf("\nInsira uma opção: ");

}

int main(){
    pilha pilha;
    int valor;
    int op = 1;

    do{
        menu();
        scanf("%d",&op);

        switch (op){

            case 1:
                criar(&pilha);
                break;
            
            case 2:
                if (vazia(&pilha) == -1){
                    printf ("\nA pilha está vazia!\n");
                }else{
                    printf ("\nA pilha tem elementos!\n");
                }
                break;

            case 3:
                printf ("\nO tamanho da pilha é: %d\n", tamanho(&pilha));
                break;
            
            case 4:
                if (vazia(&pilha) == -1){
                    printf("\n A pilha está vazia! \n");    
                }else{
                    printf("\n O topo da pilha é : %d\n", top(&pilha));
                }
                break;
            
            case 5:
                printf ("\n Insira o valor:");
                scanf (" %d", &valor);
                push (&pilha, valor);
                printf ("\n O valor: %d, foi inserido com sucesso!", valor);
                break;

            case 6:
                if (vazia(&pilha) == -1){
                    printf ("\n A pilha está vazia! \n");
                }else {
                    printf ("\n O valor :%d, foi retirado!", pop(&pilha));
                }
                break;

            case 0:
                op = 0;
                break;

            default:
                printf("\nOpção invalida!\n");
        }
    } while (op);
}
