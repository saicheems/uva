/*
 * Sai Cheemalapati
 * UVa 10469: To carry or not to carry
 *
 */

#include<cstdio>

int a, b;

int main() {
	while(scanf("%d %d", &a, &b) == 2)
		printf("%d\n", a ^ b);
}
