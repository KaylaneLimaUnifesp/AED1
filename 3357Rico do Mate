#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  int N, R, rei;
  float L, Q, agua;
  char nomes[10][13];
  scanf("%d %f %f", &N, &L, &Q);
  L = round(L * 10);
  Q = round(Q * 10);

  for (int i = 0; i < N; i++) {
    scanf("%s", nomes[i]);
  }

  R = (int)L % (N * (int)Q);

  if (R % (int)Q == 0) {
    agua = Q / 10.0;
    rei = ((int)L - 1) % (N * (int)Q) / (int)Q + 1;
    printf("%s %.1f\n", nomes[rei - 1], agua);
  } else {
    agua = (R % (int)Q) / 10.0;
    rei = R / (int)Q + 1;
    printf("%s %.1f\n", nomes[rei - 1], agua);
  }

  return 0;
}
