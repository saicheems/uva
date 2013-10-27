/*
 * Sai Cheemalapati
 * UVa 10019: Funny encryption method
 *
 */

#include<cstdio>

int N, M;

int countBits(int v) {
	int count = 0;
	while(v != 0) {
		if(v & 1) count++;
		v = v >> 1;
	}
	return count;
}

int main() {
	scanf("%d", &N);
	while(N--) {
		scanf("%d", &M);

		printf("%d ", countBits(M));
		char conv[30];
		// write the value to conv
		sprintf(conv, "%d", M);
		// read it back into M interpreted as hex
		sscanf(conv, "%x", &M);
		printf("%d\n", countBits(M));
		
	}
}
