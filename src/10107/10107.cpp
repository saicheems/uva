/*
 * Sai Cheemalapati
 * UVA 10107: What is the median?
 *
 */

#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

int n;
vector<int> list;

int main() {
	while(scanf("%d", &n) == 1) {
		list.push_back(n);
		sort(list.begin(), list.end());
		if(list.size() % 2 == 0) {
			printf("%d\n", (list[list.size() / 2] + list[list.size() / 2 - 1]) / 2);
		} else printf("%d\n", list[list.size() / 2]);
	}
}
