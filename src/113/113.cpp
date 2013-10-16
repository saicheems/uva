/*
 * Sai Cheemalapati
 * UVA 113: Power of cryptography
 *
 */

#include<cmath>
#include<cstdio>

double n, p;

int main() {
	while(scanf("%lf", &n) == 1) {
		scanf("%lf", &p);

		double r = pow(p, 1 / n);
		printf("%1.0f\n", r);
	}
}
