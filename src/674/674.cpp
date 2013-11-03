/*
 * Sai Cheemalapati
 * UVa 674: Coin change
 *
 */

#include<cstdio>

int N;
int coins[] = { 1, 5, 10, 25, 50 }, dp[10000];

int main() {
	dp[0] = 1;
	for(int i = 0; i < 5; i++) {
		for(int j = coins[i]; j < 10000; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}
	while(scanf("%d", &N) == 1) {
		printf("%d\n", dp[N]);
	}
}
