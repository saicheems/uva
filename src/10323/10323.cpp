/*
 * Sai Cheemalapati
 * UVa 10323: Factorial! You must be kidding!!!
 */

#include <cstdio>

int main () {
  int n, upper, lower;
  long long f = 1, a[20];

  // Calculate upper and lower limits for factorials.
  for (n = 1; f < 6227020800LL; n++) {
    f *= n;
    if (f < 10000) lower = n;
    a[n] = f;
  }
  upper = n;

  while (scanf("%d", &n) == 1) {
    if (n < 0) {
      if (n % 2 == 0) printf("Underflow!\n");
      else printf("Overflow!\n");
      continue;
    }
    else if (n >= upper) printf("Overflow!\n");
    else if (n <= lower) printf("Underflow!\n");
    else printf("%lld\n", a[n]);
  }
}
