/*
 * Sai Cheemalapati
 * UVA 10018: Reverse and add
 *
 */

#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int n; 
long a, b;
char input[50];

int main() {
	scanf("%d\n", &n);
	while(n--) {
		gets(input);
		int len = strlen(input);

		// convert input to long
		a = atol(input);
		// perform initial swap
		for(int i = 0; i < len/2; i++)
			swap(input[i], input[len - i - 1]);
		b = atol(input);
		
		int i = 0;
		// while a is not a palindrome
		while(a != b) {
			i++;
			// add, swap, and store
			a = a + b;
			sprintf(input, "%ld", a);
			int len = strlen(input);
			for(int i = 0; i < len/2; i++)
				swap(input[i], input[len - i - 1]);
			b = atol(input);
		}
		printf("%d %ld\n", i, a);
	}
}
