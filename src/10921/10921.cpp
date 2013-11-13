/*
 * UVa 10921: Find the telephone
 * Sai Cheemalapati
 *
 */

#include<cstdio>
#include<cstring>

char o[] = " -01ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char m[] = " -0122233344455566677778889999";
char s[35];

int main() {
	int l = strlen(o);

	while(gets(s)) {
		int n = strlen(s);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < l; j++)
				if(o[j] == s[i]) {
					printf("%c", m[j]);
					break;
				}
		}
		printf("\n");
	}
}
