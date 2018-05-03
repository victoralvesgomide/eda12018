#include "aloca_matriz.h"
#include "carrega_arquivos.h"

#define QTDE_CONJUNTO 50
#define QTDE_ALEATORIOS 25
#define TAM_ARQUIVOS 32

#include <time.h>

int main(int argc, char const *argv[]) {
  int i, aleatoriosAsfalto[QTDE_ALEATORIOS], aleatoriosGrama[QTDE_ALEATORIOS], restantesAsfalto[QTDE_ALEATORIOS], restantesGrama[QTDE_ALEATORIOS];
  FILE *treinamento[QTDE_CONJUNTO], *teste[QTDE_CONJUNTO];

  srand(time(NULL));

  geraVetorTreinamento(treinamento, aleatoriosAsfalto, aleatoriosGrama);
  geraVetorTeste(teste, aleatoriosAsfalto, aleatoriosGrama, restantesAsfalto, restantesGrama);

  for(i=0;i<QTDE_CONJUNTO;i++) {
    fclose(treinamento[i]);
    fclose(teste[i]);
  }
  return 0;
}
