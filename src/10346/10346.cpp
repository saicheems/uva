/*
 * Sai Cheemalapati
 * UVA 10346: Peter's smokes
 *
 */

#include<cstdio>

int n, k;

// number of smoked cigs, number of butts left over
int recurse(int n, int b) {
	if(n == 0) return 0;
	return n + recurse((n + b) / k, (n + b) % k);
}

int main() {
	while(scanf("%d %d", &n, &k) == 2) {
		printf("%d\n", recurse(n, 0));
	}
}
