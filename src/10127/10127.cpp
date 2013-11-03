/*
 * Sai Cheemalapati
 * UVa 10127: Ones
 *
 */

#include<cstdio>
#include<string>

using namespace std;

int n;

int digits(int n) {
	int c = 1;
	int r = 1;
	while(c % n != 0) {
		c = (c * 10 + 1) % n;
		r++;
	}
	return r;
}

int main() {
	while(scanf("%d", &n) == 1)
		printf("%d\n", digits(n));
}
