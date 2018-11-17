/////////////////////////////////////////////////////
//  Nome: Guilherme Lague
//
//
//
/////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int id;
    int valor;
    struct nodo *prox;
}fila;

//========================================================
// 
//========================================================
void insereFim(fila **inicio, fila **fim, int id, int valor){
    fila *novo;
    novo = (fila*) malloc(sizeof(fila));

    if(novo){
        novo->id = id;
        novo->valor = valor;
        novo->prox = NULL;

        if(*inicio == NULL){
            *inicio = novo;
        }else{
            (*fim)->prox = novo;
        }
        *fim= novo;
    }   
}

//========================================================
// 
//========================================================
void excluiInicio(fila **inicio, fila **fim){
    fila *novo;

    if(*inicio == NULL){
        printf("\n\tLista Vazia\n");
    }else{
        novo = *inicio;
        *inicio = (*inicio)->prox;
        if(*inicio == NULL){
            *fim = NULL;
        }
        free(novo);
    }
}

//========================================================
// 
//========================================================
void imprimir(fila **inicio){
    fila *novo;
    
    novo = *inicio;

    if(novo == NULL){
        printf("\n\tLISTA VAZIA!!!\n");
    }else{
        printf("==========================================================\n");
        printf("             Dados da fila                                \n");
        printf("==========================================================\n");
        while(novo!=NULL){
            printf("| end: %6d | id: %2d |valor: %10d | prox: %6d |\n", novo, novo->id, novo->valor, novo->prox);
            novo= novo->prox;
        }
        printf("==========================================================\n");
    }
}

//========================================================
// 
//========================================================
int main(int argc, char const *argv[]){
    fila *inicio = NULL, *fim = NULL;

    int val, op, i = 0;

    printf("=====================================\n");
    printf("    EXEMPLO DE FILA ENCADEADA\n");
    printf("=====================================\n");
    printf("1 - Inserir na fila\n");
    printf("2 - Excluir da fila\n");
    printf("3 - Mostrar a fila\n");
    printf("4 - Sair\n");
    printf("=====================================\n");
    printf("opção: ");
    scanf("%d", &op);

    do{
        switch(op){
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &val);
                insereFim(&inicio, &fim, i++, val);
            break;
            case 2:
                excluiInicio(&inicio, &fim);
            break;
            case 3:
                imprimir(&inicio);
            break;
            case 4:
                exit(0);
            break;
            default:
                printf("Opção invalida!\n\a");
        }

        printf("=====================================\n");
        printf("    EXEMPLO DE FILA ENCADEADA\n");
        printf("=====================================\n");
        printf("1 - Inserir na fila\n");
        printf("2 - Excluir da fila\n");
        printf("3 - Mostrar a fila\n");
        printf("4 - Sair\n");
        printf("=====================================\n");
        printf("opção: ");
        scanf("%d", &op);
    }while(op != 8);

    return 0;
}

