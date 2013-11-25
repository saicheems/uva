/*
 * Sai Cheemalapati
 * UVa 344: Roman digits
 *
 */

#include<cstdio>

int n;
int i_o[10] = { 0, 1, 2, 3, 1, 0, 1, 2, 3, 1 };
int v_o[10] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 };
int x_o[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

int x_t[11] = { 0, 1, 2, 3, 1, 0, 1, 2, 3, 1, 0 };
int l_t[11] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 };
int c_t[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };

int i[110], v[110], x[110], l[110], c[110];

int main() {
	i[0] = v[0] = x[0] = l[0] = c[0] = 0;
	for(int m = 1; m <= 100; m++) {
		i[m] += i[m - 1] + i_o[m % 10];
		v[m] += v[m - 1] + v_o[m % 10];
		x[m] += x[m - 1] + x_o[m % 10] + x_t[m / 10];
		l[m] += l[m - 1] + l_t[m / 10];
		c[m] += c[m - 1] + c_t[m / 10];
	}

	for(;;) {
		scanf("%d", &n);
		if(n == 0) break;
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i[n], v[n], x[n], l[n], c[n]);
	}
}
