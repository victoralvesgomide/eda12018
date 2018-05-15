#ifndef CARREGA_ARQUIVOS_H
#define  CARREGA_ARQUIVOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *carregaUmArquivoImagem(int classe, int numeroInt);
void gera25Aleatorios(int *aleatorio);
void geraVetorTreinamento(FILE **treinamento, int *aleatoriosAsfalto, int *aleatoriosGrama);
void gera25Restantes(int *aleatorios, int *restantes);
void geraVetorTeste(FILE **teste, int *aleatoriosAsfalto, int *aleatoriosGrama, int *restantesAsfalto, int *restantesGrama);

#endif
