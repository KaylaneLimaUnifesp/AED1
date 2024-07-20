/*https://resources.beecrowd.com/repository/UOJ_1383.html*/

#include <stdio.h>
#include <stdlib.h>
#define tam 9

// Função que verifica se todas as colunas possuem números de 1 a 9
int Colunas(int matriz[tam][tam], int coluna) 
{
  int numeros[tam];
  for (int i = 0; i < tam; i++) 
  {
    numeros[i]=0;
  }
  for (int i = 0; i < tam; i++)
  {
    int num = matriz[i][coluna];
    if (num < 1 || num > tam || numeros[num - 1] == 1) 
    {
      return 0;
    }
    numeros[num - 1] = 1;
  }
  return 1;
}
// Função que verifica se todas as linhas possuem números de 1 a 9
int Linhas(int matriz[tam][tam], int linha) 
{
  int numeros[tam];
  for (int i = 0; i < tam; i++) 
  {
    numeros[i]=0;
  }
  for (int i = 0; i < tam; i++) 
  {
    int num = matriz[linha][i];
    if (num < 1 || num > tam || numeros[num - 1] == 1)
    {
      return 0;
    }
    numeros[num - 1] = 1;
  }
  return 1;
}
// Função que verifica os quadrados 3x3 da matriz
int Matriz3x3 (int matriz[tam][tam], int InLinha, int InColuna) 
{
  int numeros[tam];
  for (int i = 0; i < tam; i++) 
  {
    numeros[i]=0;
  }
  for (int i = InLinha; i < InLinha + 3; i++)
  {
    for (int j = InColuna; j < InColuna + 3; j++)
    {
      int num = matriz[i][j];
      if (num < 1 || num > tam || numeros[num - 1] == 1) 
      {
        return 0;
      }
      numeros[num - 1] = 1;
    }
  }
  return 1;
}
int main() 
{
  //Entrada que informa quantas instâncias (matrizes)
  int instancias = 0;
  scanf("%d", &instancias);
  // Entrada das matrizes
  for (int i = 0; i < instancias; i++)
  {
    int matriz[tam][tam];
    for (int linha = 0; linha < tam; linha++) 
    {
      for (int coluna = 0; coluna < tam; coluna++) 
      {
        scanf("%d", &matriz[linha][coluna]);
      }
    }
    int valido = 1;
    for (int j = 0; j < tam; j++) 
    {
      if (!Linhas(matriz, j) || !Colunas(matriz, j))
      {
        valido = 0;
        break;
      }
    }
    if (valido) {
      for (int linha = 0; linha < tam; linha += 3)
      {
        for (int coluna = 0; coluna < tam; coluna += 3) 
        {
          if (!Matriz3x3 (matriz, linha, coluna)) 
          {
            valido = 0;
            break;
          }
        }
        if (!valido) {
          break;
        }
      }
    }

    if (valido)
    {
      printf("Instancia %d\nSIM\n\n", (i+1));
    } else 
    {
      printf("Instancia %d\nNAO\n\n", (i+1));
    }
  }
  return 0;
}
