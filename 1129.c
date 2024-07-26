/*https://judge.beecrowd.com/pt/problems/view/1129*/
#include <stdio.h>

int main(void){
  int n;

  while(scanf("%d", &n) && n != 0){
    for(int i = 0; i < n; i++){
      int a, b ,c, d, e, cont = 0;
      char r;
      
      scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
  
      if(a <= 127){
        r = 'A';
        cont++;
      }
        
      if(b <= 127){
        r = 'B';
        cont++;
      }
        
      if(c <= 127){
        r = 'C';
        cont++;
      }
        
      if(d <= 127){
        r = 'D';
        cont++;
      }
        
      if(e <= 127){
        r = 'E';
        cont++;
      }
  
      if(cont != 1)
        printf("*\n");
      else
        printf("%c\n", r);
  
      cont = 0;
    }
  }
  
  return 0;
}
