#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Protótipos de função
float distanciaEuclidiana(int tamanho, int* a, int* b);

// Main
int main(int argc, char const *argv[]) {
  int a[2]={2, (-3)}, b[2]={4, 5};
  float distancia;
  distancia = distanciaEuclidiana(2, a, b);
  printf("Distância euclidiana entre a e b: %.4f\n", distancia);
  return 0;
}

// Funções
float distanciaEuclidiana(int tamanho, int* a, int* b) {
    float resultado = 0;
    for(int i=0; i<tamanho; i++){
        resultado += pow((*(a+i) - *(b+i)), 2);
    }
    return sqrt(resultado);
}
