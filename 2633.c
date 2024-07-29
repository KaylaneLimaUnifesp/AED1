/*https://judge.beecrowd.com/pt/problems/view/2633*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char carne[21];
  int validade;
} Peca;

int compara(Peca *p1, Peca *p2) { return p1->validade - p2->validade; }


int main(void) {
  Peca peca[10];
  int numPecas;

  while (scanf("%d", &numPecas) != EOF) {
    if (numPecas == 0) {
      printf("\n");
      continue;
    }

    for (int i = 0; i < numPecas; i++) {
      scanf("%s %d", peca[i].carne, &peca[i].validade);
    }

       qsort(peca, numPecas, sizeof(Peca), (int(*)(const void*, const void*)) compara);

    for (int i = 0; i < numPecas; i++) {
      printf("%s", peca[i].carne);

      if (i < numPecas - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
