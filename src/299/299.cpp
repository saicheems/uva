/*
 * Sai Cheemalapati
 * UVA 299: Train swapping
 *
 */

#include<algorithm>
#include<cstdio>

using namespace std;

int n, m;
int train[50];

int main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &m);
		for(int i = 0; i < m; i++)
			scanf("%d", &train[i]);
		int swaps = 0;
		int t_swaps = 0;
		int i = 1;
		for(;;) {
			if(i >= m) {
				if(swaps > 0) i = 0, swaps = 0;
				else break;
			}
			if(train[i] < train[i - 1]) {
				swap(train[i], train[i - 1]);
				swaps++;
				t_swaps++;
			}
			i++;
		}
		printf("Optimal train swapping takes %d swaps.\n", t_swaps);
	}
}
