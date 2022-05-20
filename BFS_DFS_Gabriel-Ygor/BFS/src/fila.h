#ifndef FILA_H 
#define FILA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Item tItem;
typedef struct Block tBlock;
typedef struct Fila tFila;

struct Item{
	int x;
	int y;
};

struct Block{
	tItem pos;
	tBlock *prox;
};

struct Fila{
	tBlock *first;
	tBlock *last;
};


void FFVazia(tFila *f);
void Enfileira(tFila *f, tItem pos);
void Desenfileira(tFila *f, tItem *pos);
void FImprime(tFila *f);
void ImprimirMatriz(int tam, int **matriz);
void BFS(int **matriz, int tam);

#endif