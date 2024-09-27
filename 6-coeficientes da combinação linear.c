#include <stdio.h>

void combinacao_linear (int valores_divisao[], int valores_coeficiente[], int i, int contador)
{
    if (contador == 0) 
    {
        valores_coeficiente[i] = 1;
        valores_coeficiente[i - 1] = valores_divisao[i - 1] * valores_coeficiente[i];
    }
    else 
    {
        valores_coeficiente[i - 1] = (valores_divisao[i - 1] * valores_coeficiente[i]) + valores_coeficiente[i + 1];
    }

    if (i == 1)
    {
        if (contador % 2 != 0) 
            printf("Os valores de S e T sao: -%d e %d\n", valores_coeficiente[i], valores_coeficiente[i - 1]);
        else 
            printf("Os valores de S e T sao: %d e -%d\n", valores_coeficiente[i], valores_coeficiente[i - 1]);
        return;
    }

    combinacao_linear(valores_divisao, valores_coeficiente, i - 1, contador + 1);
}

void euclides(int a, int b, int valores_a[], int valores_b[], int valores_resto[], int valores_divisao[], int valores_coeficiente[], int i)
{
    if (b == 0)
    {
        printf("O mdc eh: %d\n", a);

        if (i > 1)
            combinacao_linear(valores_divisao, valores_coeficiente, i - 1, 0);
        else
            printf("Os valores de S e T sao: 1 e 0\n"); // caso especial onde b é múltiplo de a ou vice-versa

        return;
    }

    int aux;

    if (b > a)
    {
        aux = a;
        a = b;
        b = aux;
    }

    valores_a[i] = a;
    valores_b[i] = b;
    valores_resto[i] = a % b;
    valores_divisao[i] = a / b;

    euclides(b, a % b, valores_a, valores_b, valores_resto, valores_divisao, valores_coeficiente, i + 1);
}

int main()
{
    int a, b, arr1[20], arr2[20], arr3[20], arr4[20], arr5[20];
    
    printf("Digite dois numeros a e b para saber os coeficientes S e T da combinacao linear do mdc(a, b):\n");
    
    scanf("%d%d", &a, &b);

    if (a <= 0 || b <= 0)
    {
        printf("Combinacao invalida, tente outros numeros.\n");
        return 1;
    }

    euclides(a, b, arr1, arr2, arr3, arr4, arr5, 0);

    return 0;
}
