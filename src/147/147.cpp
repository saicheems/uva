/*
 * Sai Cheemalapati
 * UVa 147: Dollars
 *
 */

#include<cmath>
#include<cstdio>

double s;
long p[30010] = { 0 },
    c[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

int main() {
	p[0] = 1;
	for(int i = 0; i < 11; i++)
		for(int j = c[i]; j <= 30000; j++)
			p[j] += p[j - c[i]];
	for(;;) {
		scanf("%lf", &s);
		if(s == 0) break;
		printf("%6.2f%17ld\n", s, p[(int) round(s * 100)]);
	}
}
