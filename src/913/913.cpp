/*
 * UVa 913: Joana and the odd numbers
 * Sai Cheemalapati
 *
 */

#include <cstdio>

int main() {
    long long N;
    while (scanf("%lld", &N) == 1) {
        long long num = (N / 2 + 1);
        num *= num;

        printf("%lld\n", (num * 2 - 1) * 3 - 6);
    }
}
