/*
 * Sai Cheemalapati
 * UVa 568: Just the facts
 *
 */

#include<cstdio>

int N, ld[10010];

void lnd(int n) {
	long long m = 1;
	for(int i = 1; i <= n; i++) {
		m = (m * i);
		while(m % 10 == 0) m /= 10;
		m = m % 100000;
		ld[i] = m % 10;
	}
}

int main() {
	lnd(10000);
	while(scanf("%d", &N) == 1) {
		printf("%5d -> %d\n", N, ld[N]);
	}
}
