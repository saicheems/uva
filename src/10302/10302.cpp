/*
 * Sai Cheemalapati
 * UVa 10302: Summation of polynomials
 *
 */

#include<cstdio>

int x;

long long poly(int x) {
	long long sum = 0;
	for(long long i = 1; i <= x; i++) {
		sum += i * i * i;
	}
	return sum;
}

int main() {
	while(scanf("%d", &x) == 1) printf("%lld\n", poly(x));
}
