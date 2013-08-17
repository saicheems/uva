/*
 * Sai Cheemalapati
 * UVA 10035: Primary arithmetic
 *
 */

#include<cstdio>
#include<cstdlib>

using namespace std;

long long a, b;
int na, nb;
char pa[20], pb[20];

int add() {
	int c = 0, ans = 0;
	int i = na - 1, j = nb - 1;
	for(;;) {
		if(i < 0 && j < 0) break;
		if(i >= 0) {
			c += pa[i] - '0';
			i--;
		}
		if(j >= 0) {
			c += pb[j] - '0';
			j--;
		}
		if(c < 10) c = 0;
		else ans++, c /= 10;
	}	
	return ans;
}

int main() {
	for(;;) {
		scanf("%lld %lld", &a, &b);
		if(a == 0 && b == 0) break;
		
		na = sprintf(pa, "%lld", a);
		nb = sprintf(pb, "%lld", b);
		int ans = add();
		if(ans == 0)
			printf("No carry operation.\n");
		else
		printf(ans == 1? "1 carry operation.\n" : "%d carry operations.\n", ans);
	}
}
