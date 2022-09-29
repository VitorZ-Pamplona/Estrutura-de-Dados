#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

//Cria uma pilha
void criar( pilha *e, int l){ 
    e->topo = -1;
    e->limite = l;
    e->eElem = (float*)malloc (l * sizeof(float));
}

//Identifica se a pilha esta vazia ou ocupada
int vazia(struct pilha *e){ 
    if(e->topo == -1){
        return 1; //vazia
    }else{
        return 0; //ocupada
    }
}

//Identifica se a pilha esta cheia
int cheia(struct pilha *e){ 
    if(e->topo == e->limite){
        return 1;
    }else{
        return 0;
    }
}

//Adiciona o novo valor inserido ao topo da pilha
void adicionar(struct pilha *e, float valor){ 
    e->topo++;
    e->eElem [e->topo] = valor;
}

//Retira o elemento que esta no topo
float retira(struct pilha *e){ 
    float valor = e->eElem[e->topo];
    e->topo--;
    return valor;
}

//Repete a função de remoção até a pilha estar vazia
void limpar(struct pilha *e){ 
    if (e->topo != -1){
        while(e->topo != -1){
            e->topo--;
            free(e);
        }
    }
    else{
        printf("pilha vazia\n");
    }
}

void menu(){
    printf("\n|        MENU           |\n");
    printf("|    Criar pilha    [1] |\n");
    printf("|  Push (empilhar)  [2] |\n");
    printf("| Pop (desempilhar) [3] |\n");
    printf("|   Limpar pilha    [4] |\n");
    printf("|       Sair        [5] |\n");
    printf("\nInsira uma opção: ");

}

int main(){
    struct pilha minhapilha;
    int limite, opcao;
    float valor;

    while(1){//Loop infinito
        menu();
        scanf("%d",&opcao);

        switch (opcao){

            case 1: //Criar pilha

                printf("\nLimite da pilha? ");
                scanf("%d", &limite);
                criar(&minhapilha, limite-1);
                break;

            case 2://Push

                if (cheia(&minhapilha) ==1){
                    printf("\n Pilha esta cheia! \n");    
                }else{
                    printf("\nInsira o valor: ");
                    scanf("%f", &valor);
                    adicionar(&minhapilha,valor);
                }
                break;
            
            case 3://Pop

                if (vazia(&minhapilha) == 1){
                    printf("\n Pilha esta vazia! \n");    
                }else{
                    valor = retira(&minhapilha);
                    printf("\n%.2f Retirado." ,valor);
                }
                break;
            
            case 4://Limpar

                limpar(&minhapilha);
                printf("\nPilha limpa!");
                break;

            case 5://Saida
                exit(0);
                
            default: printf("\nValor invalido!\n");
        }
    }
}
