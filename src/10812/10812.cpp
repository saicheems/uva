/*
 * Sai Cheemalapati
 * UVA 10819: Beat the spread!
 *
 */

#include<cstdio>

int n, s, d, a, b;

int main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%d %d", &s, &d);

		// a + (a + d) = s
		// a = (s - d) / 2

		a = (s - d) / 2;
		b = (s - d) / 2 + d;

		if(s < d || (a + b) != s)
			printf("impossible\n");
		else
			printf("%d %d\n", b, a);
	}
}
