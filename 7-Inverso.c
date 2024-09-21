#include <stdio.h>

int mdc (int x, int y)
{
    if (y == 0) return x;
    return mdc(y, x % y);
}

int inverso(int x, int a, int b)
{
    while ((x * a) % b != 1)  x++;
    return x;
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);


    if (y == 1 || mdc(x,y) != 1) printf("O inverso de %d mod %d não existe.\n", x, y);
    else  printf("O inverso de %d mod %d é: %d.\n", x, y, inverso(1, x, y));

}

