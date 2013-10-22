/*
 * Sai Cheemalapati
 * UVa 543: Goldbach's conjecture
 *
 */

#include<bitset>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

bitset<10000010> bs;
vector<int> primes;
map<int, bool> is_prime;

void sieve(long long upper_bound) {
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= upper_bound + 1; i++) {
		if(bs[i]) {
			for(long long j = i * i; j <= upper_bound + 1; j += i)
				bs[j] = 0;
			primes.push_back((int) i);
			is_prime[i] = true;
		}
	}
}

int n;

int main() {
	sieve(1000000);
	for(;;) {
		scanf("%d", &n);
		if(n == 0) break;
		int i;
		for(i = 0; i < primes.size(); i++) {
			if(is_prime[n - primes[i]])
				break;
		}
		printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
	}
}
