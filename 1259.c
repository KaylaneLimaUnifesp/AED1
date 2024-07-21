/*https://judge.beecrowd.com/pt/problems/view/1259*/

#include <stdlib.h>

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    int par1 = (num1 % 2 == 0);
    int par2 = (num2 % 2 == 0);

    if (par1 && par2) {
        return num1 - num2; 
    } else if (!par1 && !par2) {
        return num2 - num1; 
    } else if (par1) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int num[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    qsort(num, N, sizeof(int), compare);

    for (int i = 0; i < N; i++) {
        printf("%d\n", num[i]);
    }

    return 0;
}
