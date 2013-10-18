/*
 * Sai Cheemalapati
 * UVA 575: Skew binary
 *
 */

#include<cstdio>
#include<cstring>

char input[40];

int main() {
	for(;;) {
		gets(input);
		if(strcmp(input, "0") == 0) break;
		int length = strlen(input);
		int sum = 0;
		for(int i = 0; i < length; i++) {
			int power = length - i;
			sum += (input[i] - '0') * ((1 << power) - 1);
		}
		printf("%d\n", sum);
	}
}
