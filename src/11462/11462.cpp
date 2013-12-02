/*
 * Sai Cheemalapati
 * UVa 11462: Age sort
 *
 */

#include<cstdio>
#include<queue>

using namespace std;

int n, t;
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	for(;;) {
		scanf("%d", &n);
		if(n == 0) break;

		for(int i = 0; i < n; i++) {
			scanf("%d", &t);
			q.push(t);
		}

		printf("%d", q.top());
		q.pop();
		while(!q.empty()) {
			printf(" %d", q.top());
			q.pop();
		}
		printf("\n");
	}
}
