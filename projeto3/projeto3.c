#include <stdio.h>
#include <stdlib.h>

// Definições de Tipos de Dados
typedef struct Contatos {
  char nome[100];
  char telefone[10];
  char endereco[100];
  int cep;
  char datNasc[10];
} contato;

typedef struct Lista {
  struct Lista *anterior;
  struct Lista *proximo;
  int conteudo;
} lista;

// Protótipos de Função
lista *criaListaVazia();
void adicionaInicioLista(lista *dupla);
void imprimeLista(lista *dupla);

// Main
int main(int argc, char const *argv[]) {
  lista *dupla;
  dupla = criaListaVazia();
  adicionaInicioLista(dupla);
  adicionaInicioLista(dupla);
  imprimeLista(dupla);
  /*
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
  */
  return 0;
}
// Funções
lista *criaListaVazia() {
  return NULL;
}

void adicionaInicioLista(lista *dupla) {
  lista *novo;
  novo = (lista *) malloc(sizeof(lista));
  printf("Insira o conteúdo do novo elemento da lista: ");
  scanf("%d", &novo->conteudo);
  novo->anterior = NULL;
  if(dupla == NULL)
    novo->proximo = NULL;
  else {
    novo->proximo = dupla;
    dupla->anterior = novo;
    dupla = novo;
  }
}

void imprimeLista(lista *dupla) {
  lista *aux;
  aux = NULL;
  printf("Conteúdo da lista:\n");
  for(aux = dupla; aux->proximo == NULL; aux = dupla->proximo) {
    printf("blabla\n");
    printf("%d ", aux->conteudo);
  }
}
