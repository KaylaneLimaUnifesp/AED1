/*https://judge.beecrowd.com/pt/problems/view/2381*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[21];
    int n;
};
typedef struct Aluno Aluno;

int comparando(const void *a, const void *b) {
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    return strcmp(alunoA->nome, alunoB->nome);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    Aluno alunos[N];
    for (int i = 0; i < N; i++) {
        scanf("%s", alunos[i].nome);
        alunos[i].n= i + 1;
    }
    qsort(alunos, N, sizeof(Aluno), comparando);
    printf("%s\n", alunos[K - 1].nome);
    return 0;
}
