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
}pilha;

//========================================================
// Inserere inicio
//========================================================
void insereTopo(pilha **topo, pilha **base, int id, int valor){
    pilha *novo;
    novo = (pilha *) malloc(sizeof(pilha));

    if(novo == NULL){
        printf("Não foi possivel alocar espaço de memoria!\n\a");
    }else{
        novo->id = id;
        novo->valor = valor;
        novo->prox = *topo;
        
        if(*base == NULL){
            *base = novo;
        }
        *topo = novo;
    }
}

//========================================================
// Exclui inicio
//========================================================
void excluiTopo(pilha **topo, pilha **base){
    pilha *novo;

    if(*topo == NULL){
        printf("\n\tLista Vazia\n");
    }else{
        novo = *topo;
        *topo = (*topo)->prox;
        if(*topo == NULL){
            *base = NULL;
        }
        free(novo);
    }
}

//========================================================
// 
//========================================================
void imprimir(pilha **topo){
    pilha *novo;
    
    novo = *topo;

    if(novo == NULL){
        printf("\n\tpilha vazia!!!\a\n");
    }else{
        printf("==========================================================\n");
        printf("             Dados da pilha                               \n");
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
    pilha *topo = NULL, *base = NULL;

    int val, op, i = 0;

    do{
        printf("=====================================\n");
        printf("    EXEMPLO DE PILHA ENCADEADA\n");
        printf("=====================================\n");
        printf("1 - Inserir na pilha\n");
        printf("2 - Excluir da pilha\n");
        printf("3 - Mostrar a pilha\n");
        printf("4 - Sair\n");
        printf("=====================================\n");
        printf("opção: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &val);
                insereTopo(&topo, &base, i++, val);
            break;
            case 2:
                excluiTopo(&topo, &base);
            break;
            case 3:
                imprimir(&topo);
            break;
            case 4:
                exit(0);
            break;
            default:
                printf("Opção invalida!\n\a");
        }
    }while(op != 4);

    return 0;
}

