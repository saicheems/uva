/*
 * Sai Cheemalapati
 * UVa 11332: Summing digits
 *
 */

#include<cstdio>

int n;

int recurse(int n) {
	int sum = 0;
	while(n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum / 10 == 0? sum : recurse(sum);
}

int main() {
	for(;;) {
		scanf("%d", &n);
		if(n == 0) break;
		printf("%d\n", recurse(n));
	}
}
