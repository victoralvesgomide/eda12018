#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 4

int main(int argc, char const *argv[]) {
  int i, j; // declarando variáveis auxiliares
  int matriz[LINHAS][COLUNAS]; // declarando matriz inteira

  // Preenchendo matriz inteira:
  for(i=0;i<LINHAS;i++) {
    for(j=0;j<COLUNAS;j++) {
      matriz[i][j] = (i+1)*10 + (j+1); // para que esse preenchimento funcione corretamente, devem ser
                                       // definidos nas diretivas valores de 1 a 9!
    }
  }

  // Lendo matriz inteira
  printf("Matriz lida (int matriz[%d][%d];):\n", LINHAS, COLUNAS);
  for(i=0;i<LINHAS;i++) {
    for(j=0;j<COLUNAS;j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Analisando variável auxiliar i
  printf("Note que i, a primeira dimensão da matriz, refere-se ao número de linhas:\n");
  for(i=0;i<LINHAS;i++) {
    printf("%d ", matriz[i][0]);
  }
  printf("\nOu seja, na primeira coluna temos %d linhas.", LINHAS);
  printf("\n\n");

  // Analisando variável auxiliar j
  printf("E note que j, a segunda dimensão da matriz, refere-se ao número de colunas:\n");
  for(j=0;j<COLUNAS;j++) {
    printf("%d ", matriz[0][j]);
  }
    printf("\nOu seja, na primeira linha temos %d colunas.", COLUNAS);
  printf("\n");

  return 0;
}
