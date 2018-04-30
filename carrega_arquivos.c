#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define QTDE_CONJUNTO 50
#define QTDE_ALEATORIOS 25
#define TAM_ARQUIVOS 32

// Protótipos de Função
FILE *carregaUmArquivoAleatorio(int classe, int aleatorio);
void gera25Aleatorios(int *aleatorio);
void geraVetorTreinamento(FILE **treinamento);

// Main
int main(int argc, char const *argv[]) {
  int i;
  FILE *treinamento[QTDE_CONJUNTO];
  srand(time(NULL));
  geraVetorTreinamento(treinamento);
  for(i=0;i<QTDE_CONJUNTO;i++) {
    fclose(treinamento[i]);
  }
  return 0;
}

// Funções

void geraVetorTreinamento(FILE **treinamento) {
  int aleatorios[QTDE_ALEATORIOS], i;
  gera25Aleatorios(aleatorios);
  for(i=0;i<QTDE_ALEATORIOS;i++) {
    *(treinamento+i) = carregaUmArquivoAleatorio(0, aleatorios[i]);
  }
  gera25Aleatorios(aleatorios);
  for(i=QTDE_ALEATORIOS;i<QTDE_CONJUNTO;i++) {
    *(treinamento+i) = carregaUmArquivoAleatorio(1, aleatorios[i - QTDE_ALEATORIOS]);
  }
}

FILE *carregaUmArquivoAleatorio(int classe, int aleatorio) {
  FILE *arq;
  char numero[2], numeroAux[2], nomeArquivo[TAM_ARQUIVOS];
  sprintf(numero,"%d",aleatorio);
  if (aleatorio < 10) {
    strcpy(numeroAux, "0");
    strcat(numeroAux, numero);
    strcpy(numero, numeroAux);
  }
  printf("Número convertido para string: %s\n", numero);
  if (classe == 0)
    strcpy(nomeArquivo, "DataSet/asphalt/asphalt_");
  else
    strcpy(nomeArquivo, "DataSet/grass/grass_");
  strcat(nomeArquivo, numero);
  strcat(nomeArquivo, ".txt");
  printf("Nome de arquivo gerado: %s\n", nomeArquivo);
  arq = fopen(nomeArquivo,"r");
  if(arq == NULL) {
    printf("O arquivo não pôde ser aberto!\n\n");
    exit(0);
  }
  printf("O arquivo foi aberto com sucesso!\n\n");
  return arq;
}

void gera25Aleatorios(int *aleatorio) {
  int i, j, status;
  printf("Aleatórios gerados:\n");
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
