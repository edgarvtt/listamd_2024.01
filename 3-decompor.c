#include <stdio.h>
#include <stdbool.h>



bool primo (int num, int i)
{
    if (num == 2) return true;
    if (num < 2 || num % i == 0) return false;
    if (i * i > num) return true;

    return primo (num, i + 1);
}

void decompor (int arr[], int n, int *count)
{
    int i = 2;

    while (n > 1)
    {
        while(n % i == 0 && primo(i, 2))
        {
            arr[*count] = i;
            (*count)++;
            n /= i;
        }
        i++;
    }

}

void printar(int arr[], long long int n, int i)
{
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main ()
{
    long long int n;
    scanf("%lld", &n);

    if (n < 2)
    {
        printf("Não é possivel decompor.");
        return 0;
    }

    int arr[64], count = 0;
    decompor(arr, n, &count);
    printar(arr, count, 0);
    return 0;
}