/*
 * Sai Cheemalapati
 * UVa 10970: Big chocolate
 *
 */

#include<cstdio>

int M, N;

int main() {
	while(scanf("%d %d", &M, &N) == 2)
		printf("%d\n", M * N - 1);
}
