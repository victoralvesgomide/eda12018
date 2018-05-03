#ifndef ALOCA_MATRIZ_H
#define ALOCA_MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int linhas;
extern int colunas;

FILE *abreArquivoLeitura();
int **alocaMatriz();
void desalocaMatriz(int **matriz);
void leMatriz(int **matriz, FILE *arq);
void preencheMatriz(int **matriz, FILE *arquivo);

#endif
