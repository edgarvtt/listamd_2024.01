#include <stdio.h>

int mdc (int x, int y)
{
    if (y == 0) return x;
    return mdc(y, x % y);
}

int inverso(int a, int b) 
{
    int x = 1;
    while ((x * a) % b != 1)  x++;
    return x;
}

int tcr (int a[], int m[], int n)
{
    int result = 0;
    int M = 1;

    for (int i = 0; i < n; i++)
    {
        M *= m[i];
    }

    for (int i = 0; i < n; i++)
    {
        int Mi = M / m[i];
        int inv = inverso(Mi, m[i]);
        result += a[i] * Mi * inv;
    }

    return result % M;
}

int main ()
{
    int n;
    printf("Quantas congruências você quer encontrar a solução?\n");
    scanf ("%d", &n);
    int a[n], m[n];

    printf("Digite os valores de a:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Digite os valores de m:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
    }


    int cop = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mdc(m[i], m[j]) != 1) cop = 0;
        }
    }

    if (!cop)
    {
        printf("Os módulos precisam ser coprimos!\n");
        return 1;
    }

    printf ("A solução para as congruências é: %d\n", tcr(a, m, n));


    return 0;
}