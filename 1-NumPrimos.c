#include <stdio.h>
#include <stdbool.h>

    bool primo (int num, int i)
{
     if (num == 2) return true;
     if (num < 2 || num % i == 0) return false;
     if (i * i > num) return true;

     return primo (num, i + 1);
}

    int main ()
{
     int num;

     printf("Digite um número\n");
     scanf("%d", &num);


     if (primo (num, 2)) printf("O numero é primo.\n");
     else printf("O numero nao é primo.\n");


     return 0;
}