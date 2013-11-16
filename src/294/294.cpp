/*
 * Sai Cheemalapati
 * UVa 294: Divisors
 *
 */

#include<bitset>
#include<cstdio>
#include<vector>

using namespace std;

int n, l, h;
bitset<10000010> bs;
vector<int> primes;

void sieve(long long upper_bound) {
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= upper_bound + 1; i++) {
		if(bs[i]) {
			for(long long j = i * i; j <= upper_bound + 1; j += i)
				bs[j] = 0;
			primes.push_back((int) i);
		}
	}
}

int number_of_factors(int n) {
	int pf_index = 0;
	int pf = primes[pf_index];
	int result = 1;

	while(pf * pf <= n) {
		int v = 0;
		while(n % pf == 0) {
			v++;
			n /= pf;
		}
		pf = primes[++pf_index];
		result *= (v + 1);
	}
	if(n != 1) result *= 2;

	return result;
}

int main() {
	sieve(35000);
	scanf("%d", &n);
	while(n--) {
		scanf("%d %d", &l, &h);
		int best = 0, best_index = 0;
		for(int i = l; i <= h; i++) {
			int j = number_of_factors(i);
			if(j > best) {
				best = j;
				best_index = i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, h, best_index, best);
	}
}
