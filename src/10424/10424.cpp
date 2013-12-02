/*
 * Sai Cheemalapati
 * UVa 10424: Love calculator
 *
 */

#include<cstdio>
#include<iostream>

using namespace std;

string a, b;

bool is_lower(char c) {
	return (c >= 'a' && c <= 'z');
}

bool is_upper(char c) {
	return (c >= 'A' && c <= 'Z');
}

int sum_digits(int n) {
	int sum = 0;
	while(n != 0) {
		sum += n % 10;
		n /= 10;
	}
	if(sum > 9) return sum_digits(sum);
	else return sum;
}

int main() {
	while(getline(cin, a) && getline(cin, b)) {
		int a_sum = 0, b_sum = 0;
		for(int i = 0; i < a.length(); i++) {
			if(is_lower(a[i])) a_sum += a[i] - 'a' + 1;
			if(is_upper(a[i])) a_sum += a[i] - 'A' + 1;
		}
		for(int i = 0; i < b.length(); i++) {
			if(is_lower(b[i])) b_sum += b[i] - 'a' + 1;
			if(is_upper(b[i])) b_sum += b[i] - 'A' + 1;
		}

		float f = (float) sum_digits(a_sum) / sum_digits(b_sum);
		printf("%.2f %%\n", f > 1? 100 / f : 100 * f);
	}
}
