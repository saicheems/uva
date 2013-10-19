/*
 * Sai Cheemalapati
 * UVA 10041: Vito's family
 *
 */

#include<algorithm>
#include<cstdio>

using namespace std;

int n, r;
int s[500];

int sum(int h) {
	int v = 0;
	for(int i = 0; i < r; i++) {
		if(s[i] == h) continue;
		v += abs(h - s[i]);
	}
	return v;
}

int main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &r);
		int m = 30000; // minimum
		for(int i = 0; i < r; i++) {
			scanf("%d", &s[i]);
		}
		sort(s, s + r);
		printf("%d\n", sum(s[r / 2]));
	}
}
