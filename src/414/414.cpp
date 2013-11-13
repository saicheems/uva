/*
 * Sai Cheemalapati
 * UVa 414: Machined surfaces
 *
 */

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int n;

int main() {
	for(;;) {
		scanf("%d\n", &n);
		if(n == 0) break;

		vector<string> v;
		v.resize(n);
		for(int i = 0; i < n; i++)
			getline(cin, v[i]);

		int count = 0;
		int start[n];
		int end[n];

		for(int i = 0; i < n; i++)
			start[i] = 0, end[i] = 0;

		for(int i = 0; i < v[0].length(); i++) {
			for(int j = 0; j < v.size(); j++) {
				if(v[j][i] != 'X' && start[j] == 0) start[j] = i;
			}
		}
		for(int i = v[0].length() - 1; i >= 0; i--) {
			for(int j = 0; j < v.size(); j++) {
				if(v[j][i] != 'X' && end[j] == 0) end[j] = i + 1;
			}
		}

		int min_sum = 100000;
		for(int i = 0; i < n; i++)
			min_sum = min(min_sum, end[i] - start[i]);

		for(int i = 0; i < n; i++)
			count += end[i] - min_sum - start[i];

		printf("%d\n", count);
	}
}
