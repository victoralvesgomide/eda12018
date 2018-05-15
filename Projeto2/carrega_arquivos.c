#include "carrega_arquivos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTDE_CONJUNTO 50
#define QTDE_ALEATORIOS 25
#define TAM_ARQUIVOS 32

// Funções
void geraVetorTeste(FILE **teste, int *aleatoriosAsfalto, int *aleatoriosGrama, int *restantesAsfalto, int *restantesGrama) {
  int i;
  gera25Restantes(aleatoriosAsfalto, restantesAsfalto);
  for(i=0;i<QTDE_ALEATORIOS;i++) {
    *(teste+i) = carregaUmArquivoImagem(0, restantesAsfalto[i]);
  }
  gera25Restantes(aleatoriosGrama, restantesGrama);
  for(i=QTDE_ALEATORIOS;i<QTDE_CONJUNTO;i++) {
    *(teste+i) = carregaUmArquivoImagem(1, restantesGrama[i - QTDE_ALEATORIOS]);
  }
}

void gera25Restantes(int *aleatorios, int *restantes) {
  int i, j, existente=0, cont=0;
  printf("\nRestantes gerados:\n");
  for(i=1;i<=QTDE_CONJUNTO;i++) {
    for(j=0;j<QTDE_ALEATORIOS;j++) {
      if (i == *(aleatorios+j))
        existente = 1;
    }
    if (existente == 0) {
      *(restantes+cont) = i;
      cont++;
    }
    existente = 0;
  }
  for(i=0;i<QTDE_ALEATORIOS;i++) {
    printf("%d ", *(restantes+i));
  }
  printf("\n\n");
}

void geraVetorTreinamento(FILE **treinamento, int *aleatoriosAsfalto, int *aleatoriosGrama) {
  int i;
  gera25Aleatorios(aleatoriosAsfalto);
  for(i=0;i<QTDE_ALEATORIOS;i++) {
    *(treinamento+i) = carregaUmArquivoImagem(0, aleatoriosAsfalto[i]);
  }
  gera25Aleatorios(aleatoriosGrama);
  for(i=QTDE_ALEATORIOS;i<QTDE_CONJUNTO;i++) {
    *(treinamento+i) = carregaUmArquivoImagem(1, aleatoriosGrama[i - QTDE_ALEATORIOS]);
  }
}

FILE *carregaUmArquivoImagem(int classe, int numeroInt) {
  FILE *arq;
  char numeroStr[2], numeroAux[2], nomeArquivo[TAM_ARQUIVOS];
  sprintf(numeroStr,"%d",numeroInt);
  if (numeroInt < 10) {
    strcpy(numeroAux, "0");
    strcat(numeroAux, numeroStr);
    strcpy(numeroStr, numeroAux);
  }
  if (classe == 0)
    strcpy(nomeArquivo, "DataSet/asphalt/asphalt_");
  else
    strcpy(nomeArquivo, "DataSet/grass/grass_");
  strcat(nomeArquivo, numeroStr);
  strcat(nomeArquivo, ".txt");
  arq = fopen(nomeArquivo,"r");
  if(arq == NULL) {
    printf("O arquivo não pôde ser aberto!\n");
    exit(0);
  }
  printf("O arquivo %s foi aberto com sucesso!\n", nomeArquivo);
  return arq;
}

void gera25Aleatorios(int *aleatorio) {
  int i, j, status;
  printf("\nAleatórios gerados:\n");
  for (i=0;i<QTDE_ALEATORIOS;i++) {
    do {
      *(aleatorio+i) = 1+rand() % QTDE_CONJUNTO;
      status = 1;
      for (j=0;j<i;j++)
        if (*(aleatorio+i) == *(aleatorio+j))
          status = 0;
    } while (status == 0);
    printf("%d ", *(aleatorio+i));
  }
  printf("\n\n");
}
