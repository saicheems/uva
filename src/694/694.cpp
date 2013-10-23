/*
 * Sai Cheemalapati
 * UVa 694: The Collatz sequence
 *
 */

#include<cstdio>

long long A, B, L, max = (1 << 31) - 1;

int main() {
	for(int T = 1;; T++) {
		scanf("%lld %lld\n", &A, &L);
		if(A == -1 && L == -1) break;
		B = A;
		int terms = 0;
		for(;;) {
			if(B > max || B > L) break;
			terms++;
			if(B == 1) break;
			if(B % 2) {
				// B is odd
				B = 3 * B + 1;
			} else {
				B /= 2;
			}
		}
		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", T, A, L, terms);
	}
}
