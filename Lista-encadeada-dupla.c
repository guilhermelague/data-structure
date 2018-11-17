/////////////////////////////////////////////////////
//  Nome: Guilherme Lague
//
//
//
/////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>

typedef struct nodo{
	int valor;
	struct nodo *ant;
	struct nodo *prox;
}lista_dupla;

//=================================================================
// insere valores no inicio da lista
//=================================================================
void insereInicio(lista_dupla **inicio, lista_dupla **fim, int val){
	lista_dupla *novo;
	novo = (lista_dupla*)malloc(sizeof(lista_dupla));
	
	if(novo){
		novo->valor = val;
		novo->prox= NULL;
		novo->ant= NULL;
		if(*inicio == NULL){
			novo->prox = novo->ant = NULL;
			*inicio = novo;
			*fim = novo;
		}
		else{
			novo->prox = *inicio;
			(*inicio)->ant = novo;
			*inicio = novo;
			novo->ant = NULL;
		}
	}
}

//=================================================================
// insere valores antes de algum valor da lista
//=================================================================
void insereMeio(lista_dupla **inicio, lista_dupla *k, int valor){
    lista_dupla *ant, *aux, *novo;

    if(*inicio){
        aux = *inicio;
        while((aux != NULL) && (aux != k)){
            ant = aux;
            aux = aux->prox;
        }
        if(aux){
            novo = (lista_dupla *) malloc(sizeof(lista_dupla));
            if(novo == NULL){
                printf("Não foi possivel alocar espaço de memoria!\n\a");
            }else{
                novo->valor = valor;
                if(k == *inicio){
					novo->prox = *inicio;
                    *inicio = novo;
					novo->ant == NULL;
				}else{
                    ant->prox = novo;
                    novo->prox = k;
					k->ant = novo;
					novo->ant = ant;
                }
            } 
        }else{
            printf("Nó não encontrado!\n\a");
        }
    }else{
        printf("Não existe lista!\n\a");
    }
}

//=================================================================
// insere valores no final da lista
//=================================================================
void insereFim(lista_dupla **inicio, lista_dupla **fim, int val){
	lista_dupla *novo;
	novo = (lista_dupla*)malloc(sizeof(lista_dupla));
	
	if(novo){
		novo->valor = val;
		novo->prox= NULL;
		novo->ant= NULL;
		if(*inicio == NULL){
			*fim = novo;
			*inicio = novo;
			novo->ant = NULL;
			novo->prox= NULL;
		}
		else{
			(*fim)->prox = novo;
			novo->ant = *fim;
			*fim = (*fim)->prox;
		}
		novo->prox = NULL;
	}	
}

//========================================================
// Imprime Lista do inicio ao fim
//========================================================
void imprimeListaInicioAoFim(lista_dupla **inicio){
    lista_dupla *novo;
    novo = *inicio;
    if(novo == NULL){
        printf("\n\tLISTA VAZIA!!!\n");
    }else{
        printf("==========================================================\n");
        printf("             Dados da lista                              \n");
        printf("==========================================================\n");
        while(novo != NULL){
            printf("| end: %6d | ant: %6d | valor: %6d |  prox: %6d |\n", novo, novo->ant, novo->valor, novo->prox);
            novo = novo->prox;
        }
        printf("==========================================================\n");
    }
}

//========================================================
// Imprime Lista do fim ao inicio
//========================================================
void imprimeListaFimAoInicio(lista_dupla **fim){
    lista_dupla *novo;
    novo = *fim;
    if(novo == NULL){
        printf("\n\tLISTA VAZIA!!!\n");
    }else{
        printf("==========================================================\n");
        printf("             Dados da lista                              \n");
        printf("==========================================================\n");
        while(novo != NULL){
            printf("| end: %6d | ant: %6d | valor: %6d |  prox: %6d |\n", novo, novo->ant, novo->valor, novo->prox);
            novo = novo->ant;
        }
        printf("==========================================================\n");
    }
}

//=================================================================
// Exclui elemento do inicio da lista
//=================================================================
void excluiInicio(lista_dupla **inicio, lista_dupla **fim){
    lista_dupla *novo;

    if(*inicio == NULL){
        printf("\n\tLista Vazia\n");
    }else if((*inicio)->prox == NULL){
		free(*inicio);
        *inicio = NULL;
        *fim = NULL;
	}else{
        novo = *inicio;
        (*inicio)->prox->ant = NULL;
		*inicio = (*inicio)->prox;
        
		if(*inicio == NULL){
        	*fim = NULL;
        }

		free(novo);
    }
}

//=================================================================
// Exclui elemento de uma posição da lista  
//=================================================================
void excluiMeio(lista_dupla **inicio, lista_dupla **fim, int valor){
	lista_dupla *aux;
	aux = *inicio;
    
    int flag= 0;

    if(aux==NULL){
        printf("\n\tLista Vazia!!!\n");
    }else{
        while(aux != NULL){
            if(valor == aux->valor){
                if(*fim == *inicio){ // se for um unico nó
                    *fim = NULL;
                    *inicio = NULL;
                }else if(aux == *inicio){ // se for um nó no inicio
					*inicio = (*inicio)->prox;
					(*inicio)->ant = NULL;
				}else if(aux == *fim){ // se for um nó no fim
					*fim = (*fim)->ant;
					(*fim)->prox = NULL;	
				}else{ // se for um nó intermediario
					aux->ant->prox = aux->prox;
					aux->prox->ant = aux->ant;
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

//=================================================================
// Exclui elemento do fim da lista
//=================================================================
void excluiFim(lista_dupla **inicio, lista_dupla **fim){
	if(*inicio == NULL){
		printf("\nLISTA VAZIA!!!\a\n");
	}else if((*fim)->ant == NULL){//se for um unico nó
		free(*inicio);
		*inicio = NULL;
		*fim = NULL;
	}else{ // se existirem outros nos
		*fim = (*fim)->ant;
		(*fim)->prox = NULL;	
	}
}

//=================================================================
//	Busca valor na lista
//=================================================================
void buscaValor(struct nodo **inicio, int valor){
    lista_dupla *novo, *aux;
    novo = *inicio;
    int flag = 0; 

    if(novo == NULL){
        printf("\nLista Vazia!!!\n");
    }else{
        while(novo != NULL){
            if(valor == (novo->valor)){
                printf("\n==============================================================\n");
				printf("| end: %6d | ant: %6d | valor: %6d | prox: %6d |", novo, novo->ant, novo->valor, novo->prox);
                printf("\n==============================================================\n");
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
}

//=================================================================
// Busca endereço na lista
//=================================================================
lista_dupla* buscaEndereco(lista_dupla **inicio, int valor){
    lista_dupla *novo, *aux;
    novo = *inicio;
    int flag = 0; 

    if(novo==NULL){
        printf("\nLista Vazia!!!\n");
    }else{
        while(novo != NULL){
            if(valor == novo->valor){
                aux = novo;
                flag = 1;
                return aux;
            }
            novo = novo->prox;
        }
        if(flag == 0){
            printf("\nNao foi encontrado o endereço na Lista!\n\a");
            return 0; 
        }
        flag = 0;
    }
}

//=================================================================
// Main
//=================================================================
int main(){
	lista_dupla *inicio= NULL, *fim= NULL, *aux = NULL;
	int op, valor = 1, valor2;

	do{
        printf("\n==============================================================\n");
		printf("             MENU");
        printf("\n==============================================================\n");
		printf("1 - Inserir valor no inicio\n");
        printf("2 - Inserir valor no meio\n");
		printf("3 - Inserir valor no fim\n");
		printf("4 - Excluir valor no inicio\n");
		printf("5 - Excluir valor no meio\n");
		printf("6 - Excluir valor no fim\n");
		printf("7 - Imprimir do inicio ao fim\n");
		printf("8 - Imprimir do fim ao inicio\n");
		printf("9 - Busca\n");
        printf("10 - Sair");
        printf("\n==============================================================\n");
        printf("opcao: ");
        scanf("%d",&op);
		printf("\n==============================================================\n");

		switch(op){
			case 1:
				printf("\n==============================================================\n");
				printf("                        INSERE INICIO                             ");
				printf("\n==============================================================\n");
				while(valor != 0){
					printf("Digite o valor para inserir na lista, ou 0(zero) para parar de inserir: ");
					scanf("%d",&valor);
					if(valor > 0){
						insereInicio(&inicio, &fim, valor);		
					}
					else{
						break;
					}
				}
			break;

			case 2:
				printf("\n==============================================================\n");
				printf("                        INSERE NO MEIO                            ");
				printf("\n==============================================================\n");
				printf("Digite um valor para inserir: ");
                scanf("%d", &valor);
                printf("Digite em qual valor ira colocar: ");
                scanf("%d", &valor2);
                aux = buscaEndereco(&inicio, valor2);
                insereMeio(&inicio, aux, valor);
			break;

			case 3:
				printf("\n==============================================================\n");
				printf("                           INSERE FIM                             ");
				printf("\n==============================================================\n");
				while(valor!=0){
					printf("Digite o valor para inserir na lista, ou 0(zero) para parar de inserir: ");
					scanf("%d",&valor);
					if(valor > 0){
						insereFim(&inicio, &fim, valor);		
					}
					else{
						break;
					}
				}
			break;
		
			case 4:
				printf("\n==============================================================\n");
				printf("                     EXCLUSAO DO INICIO                           ");
				printf("\n==============================================================\n");
				excluiInicio(&inicio, &fim);
			break;
			
			case 5:
				printf("\n==============================================================\n");
				printf("                       EXCLUSAO DO MEIO                           ");
				printf("\n==============================================================\n");
				printf(" Digite o valor que deseja remover: ");
				scanf("%d", &valor);
				excluiMeio(&inicio, &fim, valor);
			break;

			case 6:
				printf("\n==============================================================\n");
				printf("                       EXCLUSAO DO FIM                            ");
				printf("\n==============================================================\n");
				excluiFim(&inicio, &fim);
			break;

			case 7:
				imprimeListaInicioAoFim(&inicio);
			break;
			
			case 8:
				imprimeListaFimAoInicio(&fim);
			break;

			case 9:
				printf("\n==============================================================\n");
				printf("                             BUSCA                                ");
				printf("\n==============================================================\n");
				printf("Digite um valor para buscar: ");
				scanf("%d", &valor);
				buscaValor(&inicio, valor);
			break;

            case 10:
				exit(0);
			break;
			
			default: printf("opcao invalida!\a\n");
		}
        valor= 1;
    }while(op!=9);

	return 0;	
}
