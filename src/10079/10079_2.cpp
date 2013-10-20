/*
 * Sai Cheemalapati
 * UVA 10079: Pizza cutting
 *
 */

#include<cstdio>

long n;

int main() {
	for(;;) {
		scanf("%ld", &n);
		if(n < 0) break;
		printf("%ld\n", (n * (n + 1)) / 2 + 1);
	}
}
