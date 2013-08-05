/*
 * Sai Cheemalapati
 * UVA 677: All walks of length "n" from the first node
 *
 */

#include<cstdio>

using namespace std;

int m, n, num_paths;
int adj[50][50], path[50];
bool vis[50];

void dfs(int c, int v) {
	path[v] = c;

	if(v == n) {
		num_paths++;
		printf("(");
		for(int i = 0; i < v + 1; i++) {
			printf("%d", path[i] + 1);
			if(i < v) printf(",");
		}
		printf(")\n");
		return;
	}

	for(int i = 0; i < m; i++) {
		if(adj[c][i] == 1 && !vis[i]) {
			vis[i] = true;
			dfs(i, v + 1);
			vis[i] = false;
		}
	}
}

int main() {
	for(;;) {
		scanf("%d %d", &m, &n);
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++)
				scanf("%d", &adj[i][j]);
			vis[i] = false;
		}
		num_paths = 0;
		vis[0] = true;
		dfs(0, 0);
		if(num_paths == 0) printf("no walk of length %d\n", n);
		if(scanf("%d", &m) == -1) break;
		else printf("\n");
	}
}
