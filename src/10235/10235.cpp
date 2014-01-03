/*
 * Sai Cheemalapati
 * UVa 10235: Simply Emirp
 *
 */
 
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

char digits[16];
int n, m;
 
int main() {
    sieve(1000000);
    while(scanf("%s", digits) == 1) {

	n = atoi(digits);
	for(int i = 0; i < strlen(digits) / 2; i++)
		swap(digits[i], digits[strlen(digits) - i - 1]);
	m = atoi(digits);

	if(is_prime[n]) {
		if(is_prime[m] && n != m) {
			printf("%d is emirp.\n", n);
		} else {
			printf("%d is prime.\n", n);
		}
	} else {
		printf("%d is not prime.\n", n);
	}
    }
}
