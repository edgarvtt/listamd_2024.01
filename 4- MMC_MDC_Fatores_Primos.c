#include <stdio.h>

int pega_fator(int x, int divisor) {
    if (x % divisor == 0)
        return divisor;
    return pega_fator(x, divisor + 1);
}

int pega_mdc_fator(int x, int y) {
    if (x == 1 || y == 1)
        return 1;

    int fator1 = pega_fator(x, 2);
    int fator2 = pega_fator(y, 2);

    if (fator1 == fator2)
        return fator1 * pega_mdc_fator(x / fator1, y / fator2);
    else if (fator1 < fator2)
        return pega_mdc_fator(x / fator1, y);
    else
        return pega_mdc_fator(x, y / fator2);
}

int pega_mmc_fator(int x, int y, int mdc) {
    return (x * y) / mdc;
}

int main() {
    int x, y;

    printf("Digite dois numeros: ");
    scanf("%d %d", &x, &y);

    int mdc = pega_mdc_fator(x, y);

    int mmc = pega_mmc_fator(x, y, mdc);

    printf("MDC(%d, %d) = %d\n", x, y, mdc);
    printf("MMC(%d, %d) = %d\n", x, y, mmc);

    return 0;
}
