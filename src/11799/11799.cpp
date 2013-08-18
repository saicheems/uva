/*
 * Sai Cheemalapati
 * UVA 11799: Horror dash
 *
 */

#include<algorithm>
#include<cstdio>

using namespace std;

int T, N, c, s;

int main() {
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		scanf("%d", &N);
		s = 0;
		for(int j = 0; j < N; j++) {
			scanf("%d", &c);
			s = max(c, s);
		}
		printf("Case %d: %d\n", i, s);
	}
}
