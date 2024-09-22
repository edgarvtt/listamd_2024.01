#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int congruencia(int a, int b, int m) {

  if (a == 0) {
    if (b == 0) {
      return 1;
    } else {
      return 0;
    }
  } else {
    int x = congruencia(m % a, (b - (m / a) * a + m) % m, m);
    return (x == -1) ? -1 : ((m - (b * x) % m) * a + b) / (a * a);
  }

}

int main() {

  int a, b, m;
  printf("Digite os valores de a, b e m:\n");
  scanf("%d %d %d", &a, &b, &m);
  int x = congruencia(a, b, m);
  if (x == -1) {
    printf("Nao existe solucao.\n");
  } else {
    printf("A solucao e x == %d (mod %d).\n", x, m);
  }
  return 0;
}
