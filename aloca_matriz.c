#include <stdio.h>
#include <stdlib.h>
#define LINHAS 1025
#define COLUNAS 1025

// Protótipos de Função
FILE *abreArquivoLeitura();
//int encontraColunasImagem(FILE *arq);
int **alocaMatriz();
void desalocaMatriz(int **matriz);
void leMatriz(int **matriz);
void preencheMatriz(int **matriz, FILE *arquivo);


// Main
int main(int argc, char const *argv[]) {
  FILE *imagem;
  int colunas, **matriz;
  imagem = abreArquivoLeitura();
  matriz = alocaMatriz();
  preencheMatriz(matriz, imagem);
  leMatriz(matriz);
  desalocaMatriz(matriz);
  fclose(imagem);
  return 0;
}

// Funções
void leMatriz(int **matriz) {
  int i, j;
  for (i=0;i<LINHAS;i++) {
    for(j=0;j<COLUNAS;j++) {
      printf("%d ", matriz[i][j]);
    }
  printf("\n");
  }
}

void preencheMatriz(int **matriz, FILE *arquivo) {
  int i, j, pixel;
  for (i=0;i<LINHAS;i++) {
    for(j=0;j<COLUNAS;j++) {
      fscanf(arquivo, "%d;", &pixel);
      printf("i:%d j:%d\n", i, j);
      printf("Pixel lido: %d\n", pixel);
      matriz[i][j] = pixel;
      printf("Armazenado na matriz: %d\n\n", matriz[i][j]);
    }
  }
}

void desalocaMatriz(int **matriz) {
  int i;
  for (i=0;i<LINHAS;i++)
    free(matriz[i]);
  free(matriz);
  printf("Matriz desalocada com sucesso!\n");
}

int **alocaMatriz() {
  int **v, i;
  v = (int **) calloc (LINHAS, sizeof(int *));
  if (v == NULL) {
    printf ("** Erro: Memoria Insuficiente **");
    return (NULL);
  }
  for ( i = 0; i < LINHAS; i++ ) {
    v[i] = (int*) calloc (COLUNAS, sizeof(int));
    if (v[i] == NULL) {
      printf ("** Erro: Memoria Insuficiente **");
      return (NULL);
    }
  }
  return v;
}
/*
int **alocaMatriz() {
  int i, j;
  int **m = (int**) malloc(LINHAS * sizeof(int*));
  for (i=0;i<LINHAS;i++)
       m[i] = (int*) malloc(COLUNAS * sizeof(int));
  if (m == NULL) {
    printf("Erro na alocação da matriz!\n");
    exit(1);
  }
  printf("Matriz alocada com sucesso!\n");
  return m;
}

int encontraColunasImagem(FILE *arq) {
  int cont=1;
  char c;
  do {
    if ((c=fgetc(arq)) == ';') {
      cont += 1;
    }
  } while (c != '\n');
  return cont;
}
*/
FILE *abreArquivoLeitura() {
  FILE *arq;
  arq = fopen("DataSet/asphalt/asphalt_01.txt","r");
  if(arq == NULL) {
    printf("O arquivo não pôde ser aberto!\n");
    exit(0);
  }
  printf("O arquivo foi aberto com sucesso!\n");
  return arq;
}
