/*
 * Sai Cheemalapati
 * UVA 11498: Division of Nlogonia
 *
 */

#include<cstdio>

using namespace std;

int K, N, M, a, b;

int main() {
	for(;;) {
		scanf("%d", &K);
		if(K == 0) break;
		scanf("%d %d", &N, &M);
		for(int i = 0; i < K; i++) {
			scanf("%d %d", &a, &b);
			if(a == N || b == M)
				printf("divisa\n");
			else if(a > N && b > M)
				printf("NE\n");
			else if(a < N && b > M)
				printf("NO\n");
			else if(a > N && b < M)
				printf("SE\n");
			else
				printf("SO\n");
		}
	}
}
