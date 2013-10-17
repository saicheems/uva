/*
 * Sai Cheemalapati
 * UVA 10783: Odd sum
 *
 */

#include<cstdio>

int n, a, b;

int main() {
	scanf("%d", &n);
	for(int t = 1; t <= n; t++) {
		scanf("%d\n%d", &a, &b);
		// increment a if it is even
		a = (a % 2 == 0)? a + 1 : a;
		int sum = 0;
		for(int i = a; i <= b; i += 2)
			sum += i;
		printf("Case %d: %d\n", t, sum);
	}
}
