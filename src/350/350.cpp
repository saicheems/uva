/*
 * Sai Cheemalapati
 * UVa 350: Pseudo-random numbers
 *
 */

#include<cstdio>

int Z, I, M, L;

int main() {
	for(int T = 1;; T++) {
		scanf("%d %d %d %d", &Z, &I, &M, &L);
		if(Z == 0 && I == 0 && M == 0 && L == 0) break;

		bool m[M + 1];
		for(int i = 0; i <= M; i++)
			m[i] = false;

		int n = (Z * L + I) % M, c = 0;
		while(!m[n]) {
			m[n] = true;
			n = (Z * n + I) % M;
			c++;
		}
		printf("Case %d: %d\n", T, c);
	}
}
