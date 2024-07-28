/*https://judge.beecrowd.com/pt/problems/view/1176*/

#include <stdio.h>

void Fibonacci(unsigned long long fibonacci[]) {
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i <= 60; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}
int main() {
    int T, N;
    unsigned long long fibonacci[61];
    Fibonacci(fibonacci);
    scanf("%d", &T);  
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);  
        printf("Fib(%d) = %llu\n", N, fibonacci[N]); 
    }

    return 0;
}
