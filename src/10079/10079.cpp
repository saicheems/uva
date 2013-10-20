/*
 * Sai Cheemalapati
 * UVA 10079: Pizza cutting
 *
 */

#include<cstdio>

long n;

long pizza(long n) {
	if(n == 0) return 1;
	return pizza(n - 1) + n;
}

int main() {
	for(;;) {
		scanf("%ld", &n);
		if(n < 0) break;
		printf("%ld\n", pizza(n));
	}
}
