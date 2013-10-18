/*
 * Sai Cheemalapati
 * UVA 10696: f91
 *
 */

#include<cstdio>

int N;

int f91(int N) {
	if(N <= 100) return f91(f91(N + 11));
	else return N - 10;
}

int main() {
	for(;;) {
		scanf("%d", &N);
		if(N == 0) break;
		printf("f91(%d) = %d\n", N, f91(N));
	}
}
