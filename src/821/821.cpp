/*
 * Sai Cheemalapati
 * UVA 821: Page hopping
 *
 */

#include<algorithm>
#include<cstdio>

using namespace std;

int graph[110][110];
int T, N, a, b;

int main() {
	while(scanf("%d %d", &a, &b) == 2) {
		if(a == 0 && b == 0) break;
		T++;
		for(int i = 0; i < 100; i++)
			for(int j = 0; j < 100; j++)
				if(i == j) graph[i][j] = 0;
				else graph[i][j] = 100000;
		N = 0;
		for(;;) {
			// read values
			N = max(max(N, a), b);
			graph[a - 1][b - 1] = 1;
			scanf("%d %d", &a, &b);
			if(a == 0 && b == 0) break;
		}

		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

		int P = 0; int sum = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++)
				if(i != j && graph[i][j] != 100000) P++, sum += graph[i][j];
		}

		printf("Case %d: average length between pages = %1.3f clicks\n", T, (float) sum / P);
	}
}
