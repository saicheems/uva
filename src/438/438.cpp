/*
 * Sai Cheemalapati
 * UVa 438: The circumference of the circle
 *
 */

#include<cmath>
#include<cstdio>

double x[3], y[3], m[2], b[2];

int main() {
	while(scanf("%lf %lf %lf %lf %lf %lf", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]) == 6) {

		int i[] = { 0, 1, 2 };
		int j[] = { 1, 2, 0 };

		int k = 0;

		for(int n = 0; n < 3; n++) {
			if(k > 1 || fabs(y[j[n]] - y[i[n]]) < 1e-5) continue;
			double bx = (x[i[n]] + x[j[n]]) / 2.0;
			double by = (y[i[n]] + y[j[n]]) / 2.0;	
			m[k] = -(x[j[n]] - x[i[n]]) / (y[j[n]] - y[i[n]]);
			b[k] = -m[k] * bx + by;
			k++;
		}

		double fx = (b[1] - b[0]) / (m[0] - m[1]);
		double fy = fx * m[0] + b[0];
		double r = sqrt(pow(fx - x[1], 2) + pow(fy - y[1], 2));
		printf("%.2f\n", 2 * 3.141592653589793 * r);
	}
}
