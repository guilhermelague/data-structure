/////////////////////////////////////////////////////
//  Nome: Guilherme Lague
//
//
//
/////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int id;
    int valor;
    struct nodo *prox;
}lista;

//=================================================================
//              Inserir no Início da Lista
//=================================================================
void insereInicio(lista **inicio, lista **fim, int id, int valor){
    lista *novo;
    novo = (lista *) malloc(sizeof(lista));

    if(novo == NULL){
        printf("Não foi possivel alocar espaço de memoria!\n\a");
    }else{
        novo->id = id;
        novo->valor = valor;
        novo->prox = *inicio;
        if(*fim == NULL){
            *fim = novo;
        }
        *inicio = novo;
    }
}

//=================================================================
//              Inserir no Meio da Lista
//=================================================================
void insereMeio(lista **inicio, lista *k, int id, int valor){
    lista *ant, *aux, *novo;

    if(*inicio){
        aux = *inicio;
        while((aux != NULL) && (aux != k)){
            ant = aux;
            aux = aux->prox;
        }
        if(aux){
            novo = (lista *) malloc(sizeof(lista));
            if(novo == NULL){
                printf("Não foi possivel alocar espaço de memoria!\n\a");
            }else{
                novo->id = id;
                novo->valor = valor;
                if(k == *inicio){
                    novo->prox = *inicio;
                    *inicio = novo;
                }else{
                    ant->prox = novo;
                    novo->prox = k;
                }
            } 
        }else{
            printf("Nó não encontrado!\n\a");
        }
    }else{
        printf("Não existe lista!\n\a");
    }
}

//========================================================
//             Insere no Fim da Lista 
//========================================================
void insereFim(lista **inicio, lista **fim, int id, int valor){
    lista *novo;
    novo= (lista *) malloc(sizeof(lista));

    if(novo){
        novo->id = id;
        novo->valor= valor;
        novo->prox= NULL;
        if(*inicio==NULL){
            *inicio= novo;
        }else{
            (*fim)->prox= novo;
        }
        *fim= novo;
    }   
}

//========================================================
//             Exclui nó do Inicio da Lista 
//========================================================
void excluiInicio(lista **inicio, lista **fim){
    lista *novo;

    if(*inicio==NULL){
        printf("\n\tLista Vazia\n");
    }else{
        novo= *inicio;
        *inicio= (*inicio)->prox;
        if(*inicio==NULL){
            *fim= NULL;
        }
        free(novo);
    }
}

//========================================================
//             Exclui nó do Fim da Lista 
//========================================================
void excluiFim(lista **inicio, lista **fim){
    lista *novo, *aux;

    if(*inicio==NULL){
        printf("\n\tLista Vazia\n");
    }else if((*inicio)->prox == NULL){
        free(*inicio);
        *inicio= NULL;
        *fim= NULL;
    }else{
        aux= *inicio;
        while(aux->prox){
            novo= aux;
            aux= aux->prox;
        }
        novo->prox= NULL;
        *fim= novo;
        free(aux);
    }
}

//=========================================================
//              Exclui nó do Meio da Lista
//=========================================================
void excluiMeio(lista **inicio, lista **fim, int valor){
	lista *ant, *aux;
	aux = *inicio;
    
    int flag= 0;

    if(aux==NULL){
        printf("\n\tLista Vazia!!!\n");
    }else{
        while(aux != NULL){
            if(valor == aux->valor){
                if(*fim == *inicio){
                    *fim = NULL;
                    *inicio = NULL;
                }else{
                    if (aux == *inicio){
                        *inicio = (*inicio)->prox;
                    }else{
                        ant = *inicio;
                        while(ant->prox != aux){
                            ant = ant->prox;
                        }
                        ant->prox = aux->prox;
                    }
                }
                free(aux);	
                aux = NULL;
                flag= 1;
            }else{
                aux = aux->prox;
            }	
        }
        if(flag==0){
            printf("\n  Numero nao existe na Lista!!!\n\n");
        }
    }
}

//========================================================
//                  Imprime Lista 
//========================================================
void imprimeLista(lista **inicio){
    lista *novo;
    novo = *inicio;
    if(novo == NULL){
        printf("\n\tLISTA VAZIA!!!\n");
    }else{
        printf("==========================================================\n");
        printf("             Dados da lista                              \n");
        printf("==========================================================\n");
        while(novo != NULL){
            printf("| end: %6d | id: %2d | valor: %10d | prox: %6d |\n", novo, novo->id, novo->valor, novo->prox);
            novo = novo->prox;
        }
        printf("==========================================================\n");
    }
}

//========================================================
//                   Busca Valor 
//========================================================
void buscaValor(lista **inicio, int valor){
    lista *novo;
    novo = *inicio;
    int flag= 0; 

    if(novo==NULL){
        printf("\n\tLista Vazia!!!\n");
    }else{
        while(novo != NULL){
            if(valor == (novo->valor)){
                printf("| end: %d | valor: %d | prox: %d |\n", novo, novo->valor, novo->prox);
                flag = 1;
            }
            novo = novo->prox;
        }
        if(flag == 0){
            printf("\nNao foi encontrado o valor na lista!\n\a");
        }
        flag = 0;
    }
}

//========================================================
//                   Busca endereço 
//========================================================
lista* buscaEndereco(lista **inicio, int valor){
    lista *novo, *aux;
    novo = *inicio;
    int flag = 0; 

    if(novo==NULL){
        printf("\n\tLista Vazia!!!\n");
    }else{
        while(novo != NULL){
            if(valor == (novo->valor)){
                aux = novo;
                flag = 1;
            }
            novo = novo->prox;
        }
        if(flag == 0){
            printf("\nNao foi encontrado o valor na lista!\n\a");
        }
        flag = 0;
    }
    return aux;
}

//========================================================
//                   Main 
//========================================================
int main(){
    lista *novo = NULL, *inicio= NULL, *fim= NULL;
    int val, val2, op, i = 0;

    do{
        printf("=====================================\n");
        printf("    EXEMPLO DE LISTA ENCADEADA\n");
        printf("=====================================\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no meio\n");
        printf("3 - Inserir no fim\n");
        printf("4 - Excluir do inicio\n");
        printf("5 - Excluir do meio\n");
        printf("6 - Excluir do fim\n");
        printf("7 - Mostrar a lista\n");
        printf("8 - Buscar um valor\n");
        printf("9 - Sair\n");
        printf("=====================================\n");
        printf("opção: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &val);
                insereInicio(&inicio, &fim, i++, val);
            break;
            case 2:
                printf("Digite um valor para inserir: ");
                scanf("%d", &val);
                printf("Digite em qual valor ira colocar: ");
                scanf("%d", &val2);
                novo = buscaEndereco(&inicio, val2);
                insereMeio(&inicio, novo, i++, val);
            break;
            case 3:
                printf("Digite um valor para inserir: ");
                scanf("%d", &val);
                insereFim(&inicio, &fim, i++, val);
            break;
            case 4:
                excluiInicio(&inicio, &fim);
            break;
            case 5:
                printf("Digite um valor para excluir: ");
                scanf("%d", &val);
                excluiMeio(&inicio, &fim, val);
            break;
            case 6:
                excluiFim(&inicio, &fim);
            break;
            case 7:
                imprimeLista(&inicio);
            break;
            case 8:
                printf("Digite um valor para buscar: ");
                scanf("%d", &val);
                buscaValor(&inicio, val);
            break;
            case 9:
                exit(0);
            break;
            default:
                printf("Opção invalida!\n\a");
        }
    }while(op != 9);
    
    return 0;
}