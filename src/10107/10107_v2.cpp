/*
 * Sai Cheemalapati
 * UVA 10107: What is the median?
 *
 */

#include<cstdio>
#include<vector>

using namespace std;

int n;
vector<int> list;

int main() {
	while(scanf("%d", &n) == 1) {
		list.push_back(n);
		for(int i = 0; i < list.size(); i++)
			if(list[i] > n) swap(list[i], list[list.size() - 1]);
		if(list.size() % 2 == 0) {
			printf("%d\n", (list[list.size() / 2] + list[list.size() / 2 - 1]) / 2);
		} else printf("%d\n", list[list.size() / 2]);
	}
}
