/*
 * Sai Cheemalapati
 * UVA 100: The 3n + 1 problem
 *
 */

#include<stdio.h>

int cycle(int m) {
	int c = 1;
	while(m != 1) {
		c++;
		if(m % 2 == 0) {
			m = m / 2;
		} else {
			m = m * 3 + 1;
		}
	}
	return c;
}

int main() {

	int a, b, c, aOriginal, bOriginal, max;

	while(scanf("%d %d", &a, &b) == 2) {
		max = 0;
		aOriginal = a;
		bOriginal = b;
		if(a > b) {
			c = a;
			a = b;
			b = c;
		}
		for(int i = a; i <= b; i++) {
			int t = cycle(i);
			if(max <= t) {
				max = t;
			}
		}
		printf("%d %d %d\n", aOriginal, bOriginal, max);
	}
	return 0;
}

