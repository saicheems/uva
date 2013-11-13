/*
 * Sai Cheemalapati
 * UVa 10929: You can say 11
 *
 */

#include<cstdio>

char in[1100];

int main() {
	while(gets(in)) {
		if(in[0] == '0' && in[1] == 0) break;

		int s = 0;
		for(int i = 0; in[i] != 0; i++) {
			s += (in[i] - '0');
			s *= 10;
			s %= 11;
		}
		printf(s == 0? "%s is a multiple of 11.\n" : 
			"%s is not a multiple of 11.\n", in);
	}
}
