/*
 * Sai Cheemalapati
 * UVA 488: Triangle wave
 *
 */

#include<cstdio>

int n, a, b;

int main() {
	scanf("%d", &n);
	for(int t = 0; t < n; t++) {
		if(t > 0) printf("\n");
		scanf("%d\n%d", &a, &b);
		for(int i = 0; i < b; i++) {
			if(i > 0) printf("\n");
			for(int j = 0; j < a * 2 - 1; j++) {
				for(int k = 0; k < (j < a? j + 1 : 2 * a - 1 - j); k++) {
					printf("%d", j < a? j + 1 : 2 * a - 1 - j);
				}
				printf("\n");
			}
		}
	}
}
