/*https://judge.beecrowd.com/pt/problems/view/2929*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
  int *dados;
  int *minimos;
  int topo;
  int capacidade;
} Pilha;

void Inicializa(Pilha *pilha, int capacidade) {
  pilha->dados = (int *)malloc(capacidade * sizeof(int));
  pilha->minimos = (int *)malloc(capacidade * sizeof(int));
  pilha->topo = -1;
  pilha->capacidade = capacidade;
}

int Vazia(Pilha *pilha) { return pilha->topo == -1; }

int Minimo(Pilha *pilha) {
  if (pilha->topo == -1) {
    return -1;
  }
  return pilha->minimos[pilha->topo];
}

int Desempilha(Pilha *pilha) {
  if (pilha->topo == -1) {
    return -1;
  }
  return pilha->dados[pilha->topo--];
}

void Empilha(Pilha *pilha, int valor) {
  if (pilha->topo == pilha->capacidade - 1) {
    pilha->capacidade *= 2;
    pilha->dados =
        (int *)realloc(pilha->dados, pilha->capacidade * sizeof(int));
    pilha->minimos =
        (int *)realloc(pilha->minimos, pilha->capacidade * sizeof(int));
  }
  pilha->dados[++pilha->topo] = valor;
  if (pilha->topo == 0) {
    pilha->minimos[pilha->topo] = valor;
  } else {
    if (valor < pilha->minimos[pilha->topo - 1]) {
      pilha->minimos[pilha->topo] = valor;
    } else {
      pilha->minimos[pilha->topo] = pilha->minimos[pilha->topo - 1];
    }
  }
}

void FreePilha(Pilha *pilha) {
  free(pilha->dados);
  free(pilha->minimos);
}

int main() {
  Pilha pilha;
  int N, valor;
  char operacao[10];

  scanf("%d", &N);
  Inicializa(&pilha, N);

  for (int i = 0; i < N; i++) {
    scanf("%s", operacao);
    if (operacao[1] == 'U') {
      scanf("%d", &valor);
      Empilha(&pilha, valor);
    } else if (operacao[1] == 'O') {
      if (Vazia(&pilha)) {
        printf("EMPTY\n");
      } else {
        Desempilha(&pilha);
      }
    } else if (operacao[1] == 'I') {
      int valorMin = Minimo(&pilha);
      if (valorMin == -1) {
        printf("EMPTY\n");
      } else {
        printf("%d\n", valorMin);
      }
    }
  }
  FreePilha(&pilha);
  return 0;
}
