/*
 * Sai Cheemalapati
 * UVa 160: Factors and factorials
 *
 */

#include<bitset>
#include<cstdio>
#include<vector>

using namespace std;

bitset<10000010> bs;
vector<int> primes;
vector<vector<int> > factors;
vector<int> end_index;

int n;

void sieve(int upper_bound) {
	bs.set();
	bs[0] = bs[1] = 0;
	for(int i = 2; i < upper_bound + 1; i++) {
		if(bs[i]) {
			for(int j = i * i; j <= upper_bound + 1; j += i)
				bs[j] = 0;
			primes.push_back(i);
		}
	}
}

vector<int> prime_factors(int n) {
	vector<int> factors;
	factors.assign(101, 0);
	int pf_index = 0;
	int pf = primes[pf_index];

	while(pf * pf <= n) {
		while(n % pf == 0) {
			n /= pf;
			factors[pf]++;
		}
		pf = primes[++pf_index];
	}
	if(n != 1)
		factors[n]++;

	return factors;
}

int main() {
	sieve(100);
	factors.resize(101);
	end_index.resize(101);

	for(int i = 2; i <= 100; i++)
		factors[i] = prime_factors(i);

	for(int i = 3; i <= 100; i++)
		for(int j = 0; j < factors[i].size(); j++)
			factors[i][j] += factors[i - 1][j];

	for(int i = 100; i > 1; i--)
		for(int j = primes.size() - 1; j >= 0; j--)
			if(factors[i][primes[j]] != 0) {
				end_index[i] = j;
				break;
			}

	for(;;) {
		scanf("%d", &n);
		if(n == 0) break;
		printf("%3d! =", n);
		for(int i = 0; i < end_index[n] + 1; i++) {
			if(i > 0 && i % 15 == 0) printf("\n      ");
			printf("%3d", factors[n][primes[i]]);
		} printf("\n");
	}
}
