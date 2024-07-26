/*https://judge.beecrowd.com/pt/problems/view/1068*/

#include <stdio.h>
#include <string.h>

int main(void){
    int abre;
    char s[1000];
    while(fgets(s, sizeof(s), stdin)){
        abre = 0; 
        for(int i = 0; i < strlen(s); i++){
            if(s[i] == '(')
                abre++;
            else if(s[i] == ')')
                abre--;
            if(abre < 0)
                break;
        }
        if(abre == 0)
            printf("correct\n");
        else
            printf("incorrect\n");
    }
    return 0;
}
