/*
 * Sai Cheemalapati
 * UVa 11332: Summing digits
 *
 */

#include<cstdio>

int n;

int main() {
	for(;;) {
		scanf("%d", &n);
		if(n == 0) break;
		printf("%d\n", n % 9);
	}
}
