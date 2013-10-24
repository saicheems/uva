/*
 * Sai Cheemalapati
 * UVa 541: Error correction
 *
 */

#include<cstdio>

using namespace std;

int n;
int matrix[110][110];
int row_sum[110], col_sum[110];

int main() {
	for(;;) {
		scanf("%d", &n);
		if(n == 0) break;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				scanf("%d", &matrix[i][j]);

				if(i == 0) col_sum[j] = matrix[i][j];
				else col_sum[j] += matrix[i][j];

				if(j == 0) row_sum[i] = matrix[i][j];
				else row_sum[i] += matrix[i][j];
			}

		int r_odd = 0, c_odd = 0;
		int r, c;
		for(int i = 0; i < n; i++) {
			if(row_sum[i] % 2) r_odd++;
			if(col_sum[i] % 2) c_odd++;
			for(int j = 0; j < n; j++) {
				if(row_sum[i] % 2 && col_sum[j] % 2)
					r = i + 1, c = j + 1;
			}
		}
		if(c_odd > 1 || r_odd > 1)
			printf("Corrupt\n");
		if(c_odd == 0 && r_odd == 0)
			printf("OK\n");
		if(c_odd == 1 && r_odd == 1)
			printf("Change bit (%d,%d)\n", r, c);
	}
}
