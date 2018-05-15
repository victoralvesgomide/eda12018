#include <stdio.h>
#include <stdlib.h>

typedef struct Contatos {
  char nome[100];
  char telefone[10];
  char endereco[100];
  int cep;
  char datNasc[10];
  struct Contatos *prox;
}contato;

int main(int argc, char const *argv[]) {
  int opc;
  do {
    printf("*** Menu ***\n");
    printf("1) Inserir novo registro.\n");
    printf("2) Remover registro.\n");
    printf("3) Buscar registro.\n");
    printf("4) Visualizar agenda.\n");
    printf("5) Sair.\n");
    scanf("%d",&opc);

    if (opc == 1) {
      // função para inserir novo registro
    }
    if (opc == 2) {
      // função para remover registro
    }if (opc == 3) {
      // função para buscar registro
    }
    if (opc == 4) {
      // função para visualizar agenda
    }
  } while(opc != 5);

  return 0;
}
