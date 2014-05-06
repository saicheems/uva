/*
 * Sai Cheemalapati
 * UVa 11461: Square numbers
 */

#include <cstdio>

int main () {
  int squares[1000];
  for (int i = 0; i * i <= 100000; i++) {
    squares[i] = i * i;
  }

  int a, b;
  while (scanf("%d %d", &a, &b)) {
    if (a == 0 && b == 0) break;
    int count = 0;
    for (int i = 1; i < 1000; i++) {
      if (b < squares[i]) break;
      if (a <= squares[i]) count++;
    }
    printf("%d\n", count);
  }
}
