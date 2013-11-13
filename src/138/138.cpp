/*
 * Sai Cheemalapati
 * UVa 138: Street numbers
 *
 */

#include<cmath>
#include<cstdio>

int main() {
	long n = 0;
	double i = 8;
	while(n < 10) {
		double j = sqrt(i * (i + 1) / 2);
		if(j == (long) j) {
			printf("%10ld%10ld\n", (long) j, (long) i);
			n++;
		}
		i++;
	}
}
