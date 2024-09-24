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
    int a[3];
    int m[3];

    printf("Digite os valores de a1, a2 e a3:\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Digite os valores de m1, m2 e m3:\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &m[i]);
    }

    if (mdc(m[0], m[1]) != 1 || mdc(m[1], m[2]) != 1 || mdc(m[0], m[2]) != 1)
    {
        printf("Os módulos precisam ser coprimos!\n");
        return 1;
    }

    printf ("%d", tcr(a, m, 3));


    return 0;
}