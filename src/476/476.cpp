/*
 * Sai Cheemalapati
 * UVa 476: Points in figures: rectangles
 *
 */

#include<cmath>
#include<cstdio>

int n;
char input[500];
float px, py;
float ax[12], ay[12], bx[12], by[12];

int main() {
	for(n = 0;; n++) {
		gets(input);
		if(input[0] == '*') break;
		sscanf(input, "r %f %f %f %f", &ax[n], &ay[n], &bx[n], &by[n]);
	}
	for(int m = 0;; m++) {
		scanf("%f %f", &px, &py);
		if(fabs(px - 9999.9) < 1e-3 && fabs(py - 9999.9) < 1e-3) break;
		int count = 0;
		for(int i = 0; i < n; i++) {
			if(px > ax[i] && px < bx[i] && py < ay[i] && py > by[i]) {
				printf("Point %d is contained in figure %d\n", m + 1, i + 1);
				count++;
			}
		}
		if(count == 0) printf("Point %d is not contained in any figure\n", m + 1);
	}
}
