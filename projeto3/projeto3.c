#include <stdio.h>
#include <stdlib.h>

// Definições de Tipos de Dados
typedef struct Contatos {
  char nome[100];
  char telefone[10];
  char endereco[100];
  long int cep;
  char datNasc[10];
} contato;

typedef struct Lista {
  struct Lista *anterior;
  struct Lista *proximo;
  contato conteudo;
} lista;

// Protótipos de Função
lista *criaListaVazia();
lista *adicionaInicioLista(lista *dupla);
void imprimeLista(lista *dupla);
void escreveArquivo(lista *dupla);

// Main
int main(int argc, char const *argv[]) {
  lista *dupla;
  dupla = criaListaVazia();

  int opc;
  do {
    printf("*** Menu ***\n");
    printf("1) Inserir novo registro.\n");
    printf("2) Remover registro.\n");
    printf("3) Buscar registro.\n");
    printf("4) Visualizar agenda.\n");
    printf("5) Sair.\n");
    scanf("%d",&opc);

    switch(opc) {
      case 1:
        dupla = adicionaInicioLista(dupla);
        break;
      case 2:
        // removeRegistro
        break;
      case 3:
        // buscaRegistro
        break;
      case 4:
        printf("Conteúdo da lista:\n");
        imprimeLista(dupla);
    }
  } while (opc != 5);

/*
    if (opc == 1) {
      dupla = adicionaInicioLista(dupla);
    }
    if (opc == 2) {
      // função para remover registro
    }if (opc == 3) {
      // função para buscar registro
    }
    if (opc == 4) {
      printf("Conteúdo da lista:\n");
      imprimeLista(dupla);
    }
  } while(opc != 5);
*/

  escreveArquivo(dupla);
  return 0;
}
// Funções
lista *criaListaVazia() {
  return NULL;
}

lista *adicionaInicioLista(lista *dupla) {
  lista *novo;
  novo = (lista *) calloc(1, sizeof(lista));
  if (novo == NULL) {
    return 0;
  }
  
/*
  printf("Nome: "); fgets(novo->conteudo.nome, 100, stdin);
  printf("Telefone: "); fgets(novo->conteudo.telefone, 10, stdin);
  printf("Endereco: "); fgets(novo->conteudo.endereco, 100, stdin);
  printf("CEP: "); scanf("%ld", &novo->conteudo.cep);
  printf("Data de Nascimento: "); fgets(novo->conteudo.datNasc, 10, stdin);
*/

  fflush(stdin);
  printf("Nome: "); scanf("%s", novo->conteudo.nome);
  fflush(stdin);
  printf("Telefone: "); scanf("%s", novo->conteudo.telefone);
  fflush(stdin);
  printf("Endereco: "); scanf("%s", novo->conteudo.endereco);
  fflush(stdin);
  printf("CEP: "); scanf("%ld", &novo->conteudo.cep);
  fflush(stdin);
  printf("Data de Nascimento: "); scanf("%s", novo->conteudo.datNasc);

  //escreveArquivo(novo);

  novo->proximo = dupla;
  novo->anterior = NULL;
  if (dupla != NULL) {
    dupla->anterior = novo;
  }
  dupla = novo;
  return dupla;
}

void imprimeLista(lista *dupla) {
  if (dupla == NULL) {
    printf("\n");
    return;
  } else {
      printf("Nome: ");
      printf("%s\n", dupla->conteudo.nome);
      printf("Telefone: ");
      printf("%s\n", dupla->conteudo.telefone);
      printf("Endereco: ");
      printf("%s\n", dupla->conteudo.endereco);
      printf("CEP: ");
      printf("%ld\n", dupla->conteudo.cep);
      printf("Data de Nascimento: ");
      printf("%s\n", dupla->conteudo.datNasc);
      imprimeLista(dupla->proximo);
  }
}

void escreveArquivo(lista *dupla) {
  FILE *arq = fopen("contatos.txt", "w");
  if (arq == NULL) {
    printf("Falha");
    exit(1);
  }
  fprintf(arq, "%s\n", dupla->conteudo.nome);
  fprintf(arq, "%s\n", dupla->conteudo.telefone);
  fprintf(arq, "%s\n", dupla->conteudo.endereco);
  fprintf(arq, "%ld\n", dupla->conteudo.cep);
  fprintf(arq, "%s\n", dupla->conteudo.datNasc);
  fprintf(arq, "%s\n", "$");
  if(dupla->proximo != NULL) {
    escreveArquivo(dupla->proximo);
  }

/*
  FILE *arq = fopen("contatos.txt", "a+");
  if (arq == NULL) {
    printf("Falha");
    exit(1);
  }
    fprintf(arq, "%s\n", dupla->conteudo.nome);
    fprintf(arq, "%s\n", dupla->conteudo.telefone);
    fprintf(arq, "%s\n", dupla->conteudo.endereco);
    fprintf(arq, "%ld\n", dupla->conteudo.cep);
    fprintf(arq, "%s\n", dupla->conteudo.datNasc);
    fprintf(arq, "%s\n", "$");
*/
}
