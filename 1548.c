/*https://judge.beecrowd.com/pt/problems/view/1548*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nota;
    int posOrig;
} Aluno;

int compara(const void *a, const void *b) {
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    return alunoB->nota - alunoA->nota;
}

int main() {
    int numTest;
    scanf("%d", &numTest);

    while (numTest--) {
        int numAlunos;
        scanf("%d", &numAlunos);

        Aluno alunos[numAlunos];
        Aluno alunosOrd[numAlunos];

        for (int i = 0; i < numAlunos; i++) {
            scanf("%d", &alunos[i].nota);
            alunos[i].posOrig = i;
            alunosOrd[i] = alunos[i];
        }

        qsort(alunosOrd, numAlunos, sizeof(Aluno), compara);

        int contaux = 0;
        for (int i = 0; i < numAlunos; i++) {
            if (alunosOrd[i].posOrig == i) {
                contaux++;
            }
        }

        printf("%d\n", contaux);
    }

    return 0;
}
