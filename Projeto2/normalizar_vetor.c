#include <stdio.h>
#include <stdlib.h>

float minVetor(int tam, int *vec);
float maxvetor(int tam, int *vec);
void normalizar(int tam, float *vec);

int main(int argc, char const *argv[]) {

  float vec[5] = {1, 2, 3, 4, 5};
  normalizar(5, vec);

  for (int i = 0; i < 5; i++) {
    printf("%.2f\n", vec[i]);
  }
  return 0;
}

float minVetor(int tam, float *vec) {
  float min = *vec;
  for (int i = 0; i < tam; i++) {
    if (*(vec + i) < min) {
      min = *(vec + i);
    }
  }
  return min;
}

float maxVetor(int tam, float *vec) {
  float max = *vec;
  for (int i = 0; i < tam; i++) {
    if (*(vec + i) > max) {
      max = *(vec + i);
    }
  }
  return max;
}

void normalizar(int tam, float *vec) {
  float menor, maior;
  menor = minVetor(tam, vec);
  maior = maxVetor(tam, vec);
  for (int i = 0; i < tam; i++) {
    *(vec + i) = (*(vec + i) - menor)/(maior - menor);
  }
}
