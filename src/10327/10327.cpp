/*
 * Sai Cheemalapati
 * UVa 10327: Flip sort
 *
 */

#include<algorithm>
#include<cstdio>

using namespace std;

int N;
int a[1010];

int main() {
	while(scanf("%d", &N) == 1) {
		for(int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		int t_flips = 0;
		int flips = 0;
		int k = 1;

		for(;;) {
			if(k >= N) {
				if(flips == 0) break;
				else k = 1, flips = 0;
			}
			if(a[k] < a[k - 1]) {
				swap(a[k], a[k - 1]);
				flips++, t_flips++;
			}
			k++;
		}

		printf("Minimum exchange operations : %d\n", t_flips);
	}
}
