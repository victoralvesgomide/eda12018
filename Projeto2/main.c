// Trabalho 2
// Estruturas de Dados e Algoritmos
// Prof. Matheus Mendelson

// Grupo:
// Victor Alves Gomide - 15/0150741
// Wellingthon Diego Resende de Lima - 15/0152183

#include "aloca_matriz.h"
#include "carrega_arquivos.h"

#define QTDE_CONJUNTO 50
#define QTDE_ALEATORIOS 25
#define TAM_ARQUIVOS 32

#include <time.h>

int main(int argc, char const *argv[]) {
  int **matriz;
  int i, aleatoriosAsfalto[QTDE_ALEATORIOS], aleatoriosGrama[QTDE_ALEATORIOS], restantesAsfalto[QTDE_ALEATORIOS], restantesGrama[QTDE_ALEATORIOS];
  FILE *treinamento[QTDE_CONJUNTO], *teste[QTDE_CONJUNTO], *temp;

  srand(time(NULL));

  geraVetorTreinamento(treinamento, aleatoriosAsfalto, aleatoriosGrama);
  geraVetorTeste(teste, aleatoriosAsfalto, aleatoriosGrama, restantesAsfalto, restantesGrama);

  temp = fopen("temp.txt","w");

  matriz = alocaMatriz();
  preencheMatriz(matriz, treinamento[0]);
  leMatriz(matriz, temp);
  desalocaMatriz(matriz);

  fclose(temp);

  for(i=0;i<QTDE_CONJUNTO;i++) {
    fclose(treinamento[i]);
    fclose(teste[i]);
  }
  return 0;
}
