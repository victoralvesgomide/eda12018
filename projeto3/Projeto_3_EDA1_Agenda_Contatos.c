// Estruturas de Dados e Algoritmos 1
// Prof. Mateus Mendelson
// Projeto 3: Agenda de Contatos

// Grupo:
// Wellingthon Diego Resende de Lima - 15/0152183
// Victor Alves Gomide - 15/0150741

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definições de Tipos de Dados
typedef struct Contatos {
  char nome[100];
  char telefone[11];
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
void escreveArquivo(lista *dupla, char *modo);
void desalocaLista(lista *dupla);

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
  escreveArquivo(dupla, "w");
  desalocaLista(dupla);
  return 0;
}

// Funções
void desalocaLista(lista *dupla) {
  while(dupla->proximo != NULL) {
    lista *aux;
    aux = dupla;
    dupla = dupla->proximo;
    free(aux);
  }
  free(dupla);
}

lista *criaListaVazia() {
  return NULL;
}

lista *adicionaInicioLista(lista *dupla) {
  lista *novo;
  novo = (lista *) calloc(1, sizeof(lista));
  if (novo == NULL) {
    return 0;
  }

  setbuf(stdin,NULL);
  printf("Nome: "); scanf("%[^\n]s", novo->conteudo.nome);
  setbuf(stdin,NULL);

  int i;
  char telAux[6];
  printf("Telefone (apenas digitos): ");
  for(i=0;i<5;i++) {
    telAux[i] = getchar();
  }
  strcpy(novo->conteudo.telefone, telAux);
  strcat(novo->conteudo.telefone, "-");
  for(i=0;i<4;i++) {
    telAux[i] = getchar();
  }
  telAux[4] = '\0';
  strcat(novo->conteudo.telefone, telAux);
  puts(novo->conteudo.telefone);

  //setbuf(stdin,NULL);
  printf("Endereco: "); scanf("%[^\n]s", novo->conteudo.endereco);
  setbuf(stdin,NULL);
  printf("CEP: "); scanf("%ld", &novo->conteudo.cep);
  setbuf(stdin,NULL);
  printf("Data de nascimento: "); scanf("%[^\n]s", novo->conteudo.datNasc);

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

void escreveArquivo(lista *dupla, char *modo) {
  FILE *arq = fopen("contatos.txt", modo);
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
  fclose(arq);
  if(dupla->proximo != NULL) {
    escreveArquivo(dupla->proximo, "a");
  }
}
