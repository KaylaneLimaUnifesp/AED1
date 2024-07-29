/*https://judge.beecrowd.com/pt/problems/view/1023*/


#include <stdio.h>


int main()
{
    int T = 0;
    long long N, X, Y;
    long long totalX, totalY;
    int consumos[201];

    while (1)
    {
        scanf("%lld", &N); 
        if (N == 0) break;
        for (int i = 0; i <= 200; ++i) {
            consumos[i] = 0;

        totalX = 0;
        totalY = 0;
        }

        printf("\n");
        for (long long i = 0; i < N; ++i)
        {
            scanf("%lld %lld", &X, &Y); 
            totalX += X;
            totalY += Y;

            if (X > 0 && Y / (double)X <= 200) { 
                consumos[Y / X] += X;
            }
        }

        printf("Cidade# %d:\n", ++T);
        int primeiro = 1;
        for (int i = 0; i <= 200; ++i)
        {
            if (consumos[i] > 0)
            {
                if (!primeiro)
                    printf(" ");
                primeiro = 0;
                printf("%d-%d", consumos[i], i);
            }
        }
        printf("\n");
        double consMed = (double)totalY / totalX;
        int consMedint = (int)(consMed * 100); 
        consMed = consMedint / 100.0; 
        printf("Consumo medio: %.2lf m3.\n", consMed);
    }

    return 0;
}
