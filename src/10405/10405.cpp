/*
 * Sai Cheemalapati
 * UVa 10405: Longest common subsequence
 *
 */

#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int n, m, i, j;
int table[1100][1100];
char a[1100], b[1100];

int main() {
	while(gets(a) && gets(b)) {
		int n = strlen(a), m = strlen(b);

		memset(table, 0, sizeof table);

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) {
				if(a[i - 1] == b[j - 1])
					table[i][j] = table[i - 1][j - 1] + 1;
				else
					table[i][j] = max(table[i][j - 1], table[i - 1][j]);
			}
		printf("%d\n", table[n][m]);
	}
}
