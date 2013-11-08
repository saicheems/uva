/*
 * Sai Cheemalapati
 * UVa 530: Binomial showdown
 *
 */

#include<algorithm>
#include<cstdio>

using namespace std;

long long n, k;

long long nchoosek(long long n, long long k) {
	long long j = 1;
	long long fact = 1;

	long long i_s = max(n - k, k) + 1, j_e = min(n - k, k);

	for(int i = i_s; i <= n; i++) {
		for(; j <= j_e; j++)
			if(fact % j == 0) fact /= j;
			else break;
		fact *= i;
	}

	for(; j <= j_e; j++)
		fact /= j;

	return fact;
}

int main() {
	for(;;) {
		scanf("%lld %lld", &n, &k);
		if(n == 0 && k == 0) break;

		printf("%lld\n", nchoosek(n, k));
	}
}
