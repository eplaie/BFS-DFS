#include "pilha.h"


void FPVazia(Pilha *p){
	p->top   = 0;
	p->base  = 0;
}


void PUSH(Pilha *p, ItemPilha d){
	if (p->top >= MAXTAM){
		printf("PILHA CHEIA!\n");
	}else{
		p->vet[p->top] = d;
		p->top ++;
	}
}

void POP(Pilha *p, ItemPilha *d){
	if(p->base == p->top){
		// printf("PILHA VAZIA!\n");
	}
	else{
		p->top --;
		*d = p->vet[p->top];
	}
}

// void PRemove(Pilha *p, ItemPilha d){
// 	Pilha aux;
// 	ItemPilha rem;

// 	FPVazia(&aux);

// 	if(p->base == p->top)
// 		printf("PILHA VAZIA!\n");
// 	else{
// 		while(p->top > p->base){
// 			POP(p, &rem);
// 			if(rem.x != d.x && rem.y != d.y)
// 				PUSH(&aux, rem);
// 		}

// 		while(aux.top > aux.base){
// 			POP(&aux, &rem);
// 			PUSH(p, rem);
// 		}
// 	}
// }

void ImprimirMatriz(int tam, int **matriz)
{
	
	for (int i = 0; i < tam; i++)
	{
		printf("\n");
		for (int j = 0; j < tam; j++)
		{
			if(matriz[i][j] == -1){
				printf("#\t");
			} else {
				printf("%d\t", matriz[i][j]);
			}

			
		}
	}
	printf("\n\n");
}

void DFS(int **matriz, int tam){
    ItemPilha aux;
    Pilha p;
    FPVazia(&p);
    int i = 0, j = 0;
    int count=0;
    aux.x=i;
    aux.y=j;
	// matriz[j][i] = 1;
    PUSH(&p, aux);
	printf("tam: %d\n", matriz[tam-1][tam-1]);

		if(matriz[0][0] != 0 || matriz[tam-1][tam-1] !=0){
			printf("\nA primeira ou ultima posicao e uma parede\n");
			return;
		} else {
			matriz[j][i] = 1;
		}
	int auxi = 0, auxj = 0, controle = 0;

    while(matriz[tam-1][tam-1] != 1){
		auxi = i;
		auxj = j;
		if(j == 0){
			if(i < tam - 1 && matriz[i + 1][j] == 0){
				i++;
				aux.x = i;
				aux.y = j;
				matriz[i][j] = 1;
				PUSH(&p, aux);
				count++;
			}
			else if(matriz[i][j + 1] == 0){
				j++; 
				aux.x = i;
				aux.y = j;
				matriz[i][j] = 1;
				PUSH(&p, aux);
				count++;
			}
			else if(matriz[i - 1][j] == 0){
				i--;
				aux.x = i;
				aux.y = j;
				matriz[i][j] = 1;
				PUSH(&p, aux);
				count++;
			}else {
				aux.x=i;
				aux.y=j;
				matriz[i][j] = 1;
				POP(&p, &aux);
				i--;
				count++;
			}
		}
		else if(i != tam - 1 && j == tam - 1){
			if(i < tam - 1 && matriz[i + 1][j] == 0){
				i++;
				aux.x = i;
				aux.y = j;
				matriz[i][j] = 1;
				PUSH(&p, aux);
				count++;
			}else if(i < tam - 1 && matriz[i][j - 1] == 0){
				j--;
				aux.x = i;
				aux.y = j;
				matriz[i][j] = 1;
				PUSH(&p, aux);
				count++;
			}else{
				aux.x=i;
				aux.y=j;
				matriz[i][j] = 1;
				POP(&p, &aux);
				count++;
			}
		}

		else{
			if(i < tam - 1 && matriz[i + 1][j] == 0){
				i++;
				aux.x = i;
				aux.y = j;
				matriz[i][j] = 1;
				PUSH(&p, aux);
				count++;
			}
			else if(matriz[i][j + 1] == 0){//
				j++; 
				aux.x = i;
				aux.y = j;
				matriz[i][j] = 1;
				PUSH(&p, aux);
				count++;
			}
			else if(matriz[i][j - 1] == 0){//
				j--;
				aux.x = i;
				aux.y = j;
				matriz[i][j] = 1;
				PUSH(&p, aux);
				count++;
			}
			else if(matriz[i - 1][j] == 0){
				i--;
				aux.x = i;
				aux.y = j;
				matriz[i][j] = 1;
				PUSH(&p, aux);
				count++;
			}
			else{
				aux.x=i;
				aux.y=j;
				matriz[i][j] = 1;
				POP(&p, &aux);
				i--;
				count++;
			}
		}
		if(auxi == i && auxj == j) {
			printf("caminho indisponivel para o final\n");
			controle = 1;
			break;
		}
    }
	if(controle == 0)
    	printf("\nPara chegar ao final da matriz usando o metodo DFS, foi realizado um total de %d interacoes!\n", count);
}