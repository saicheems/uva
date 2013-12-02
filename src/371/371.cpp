/*
 * Sai Cheemalapati
 * UVa 371: Ackerman functions
 *
 */

#include<cstdio>
#include<map>

using namespace std;

map<long, int> m;
long l, h;

int c(long x) {
	if(m[x] != 0) return m[x];

	long y = x % 2? 3 * x + 1 : x / 2;
	if(y == 1) return 1;
	return m[x] = c(y) + 1;
}

int main() {
	for(;;) {
		scanf("%ld %ld", &l, &h);
		if(l == 0 && h == 0) break;
		if(l > h) swap(l, h);

		long b = 0, bi = l;

		for(long i = l; i <= h; i++) {
			if(c(i) > b) {
				b = c(i);
				bi = i;
			}
		}
		printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n", l, h, bi, b);
	}
}
