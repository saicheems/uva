/*
 * Sai Cheemalapati
 * UVA 10370: Above average
 *
 */

#include<cstdio>

int C, N;
int g[1000];

int main() {
	scanf("%d", &C);
	while(C--) {
		scanf("%d", &N);
		float avg = 0.0;
		for(int i = 0; i < N; i++) {
			scanf("%d", &g[i]);
			avg += g[i];
		}
		avg = avg / N;
		float avg2 = 0.0;
		for(int i = 0; i < N; i++)
			if(g[i] > avg)
				avg2 += 100;

		printf("%2.3f%%\n", avg2 / N);
	}
}
