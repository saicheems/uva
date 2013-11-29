/*
 * Sai Cheemalapati
 * UVa 10260: Soundex
 *
 */

#include<cstdio>

char in[100];
int o;

int soundex(char c) {
	switch(c) {
		case 'B':case 'F':case 'P':case 'V':
			return 1;
		case 'C':case 'G':case 'J':case 'K':case 'Q':case 'S':case 'X':
		case 'Z':
			return 2;
		case 'D':case 'T':
			return 3;
		case 'L':
			return 4;
		case 'M':case 'N':
			return 5;
		case 'R':
			return 6;
	}
	return -1;
}

int main() {
	while(scanf("%s", in) == 1) {
		o = -1;
		for(int i = 0;; i++)
			if(in[i] == 0) break;
			else
				if(soundex(in[i]) != o &&
					(o = soundex(in[i])) > 0)
					printf("%d", o);
		printf("\n");
	}
}
