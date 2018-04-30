#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Protótipos de Função
FILE *carregaUmArquivoAleatorio(int classe);

// Main
int main(int argc, char const *argv[]) {
  srand(time(NULL));
  FILE *arq;
  arq = carregaUmArquivoAleatorio(1);
  fclose(arq);
  return 0;
}

// Funções
FILE *carregaUmArquivoAleatorio(int classe) {
  FILE *arq;
  int aleatorio;
  char numero[2], numeroAux[2], nomeArquivo[50];
  aleatorio = 1+rand() % 50;
  sprintf(numero,"%d",aleatorio);
  if (aleatorio < 10) {
    strcpy(numeroAux, "0");
    strcat(numeroAux, numero);
    strcpy(numero, numeroAux);
  }
  if (classe == 0)
    strcpy(nomeArquivo, "DataSet/asphalt/asphalt_");
  else
    strcpy(nomeArquivo, "DataSet/grass/grass_");
  strcat(nomeArquivo, numero);
  strcat(nomeArquivo, ".txt");
  puts(nomeArquivo);
  arq = fopen(nomeArquivo,"r");
  if(arq == NULL) {
    printf("\nO arquivo não pôde ser aberto!\n");
    exit(0);
  }
  printf("\nO arquivo %s foi aberto com sucesso!\n", nomeArquivo);
  return arq;
}
