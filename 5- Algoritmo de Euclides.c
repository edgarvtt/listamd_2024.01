#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return mdc(y, x % y);
    }
}

int main() {
    int a, b;

    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    printf("O MDC de %d e %d = %d\n", a, b, mdc(a, b));

    return 0;
}
