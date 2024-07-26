/*https://judge.beecrowd.com/pt/problems/view/1069*/

#include <stdio.h>
#include <string.h>

int main() {
  int num, i, contA, contD;
  char seq[1001];
  scanf("%d", &num);
  while (num--) {
    scanf("%s", seq);
    contA = contD = 0;
    for (i = 0; i < strlen(seq); i++) {
      if (seq[i] == '<') {
        contA++;
      } else if (seq[i] == '>') {
        if (contA > 0) {
          contD++;
          contA--;
        }
      }
    }
    printf("%d\n", contD);
  }
  return 0;
}
