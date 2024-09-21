#include <stdio.h>
#include <stdbool.h>
#include <time.h>



bool primo (int num, int i)
{
     if (num == 2) return true;
     if (num < 2 || num % i == 0) return false;
     if (i * i > num) return true;

     return primo (num, i + 1);
}

void printar (int n, time_t inicio)
{
    while (time(0) - inicio <= 60)
    {
        if(primo(n, 2)) printf("%d\n", n);
        n++;
    }
    return;
}

int main ()
{
    time_t inicio = time(0);
    printar(2, inicio);
}