/*
 * Sai Cheemalapati
 * UVA 10696: f91
 *
 */

#include<cstdio>

int N;

int main() {
	for(;;) {
		scanf("%d", &N);
		if(N == 0) break;
		printf("f91(%d) = ", N);
		if(N >= 101) printf("%d\n", N - 10);
		if(N <= 100) printf("%d\n", 91);
	}
}
