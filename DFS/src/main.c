#include "pilha.h"

int main()
{
    int tam = 0, i = 0, j = 0;
    int **matriz;

    FILE *arquivo;

    arquivo = fopen("matriz.txt", "r");

    if (arquivo == NULL)
    {
        printf("\nArquivo inválido.\n");
        return 0;
    }

    fscanf(arquivo, "%d", &tam);

    matriz = (int **)malloc(sizeof(int *) * tam);
    for (i = 0; i < tam; i++)
    {
        matriz[i] = (int *)malloc(sizeof(int) * tam);
    }

    for(i=0;i<tam; i++){
        for(j=0; j<tam; j++){
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }
    
    DFS(matriz, tam);
    printf("\nMatriz final: \n");
    ImprimirMatriz(tam, matriz);


    fclose(arquivo);



    return 0;
}