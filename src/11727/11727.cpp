/*
 * Sai Cheemalapati
 * UVA 11727
 *
 */

#include<algorithm>
#include<cstdio>

using namespace std;

int T;
int salaries[3];

int main() {
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		for(int j = 0; j < 3; j++)
			scanf("%d", &salaries[j]);
		sort(salaries, salaries + 3);
		printf("Case %d: %d\n", i, salaries[1]);
	}
}
