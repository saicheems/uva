/*
 * Sai Cheemalapati
 * UVA 167: The sultan's successors
 *
 */

#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

int k, tmax;
int board[10][10];
pair<int, int> queens[10];


bool conflict(int q, int r, int c) {
	for(int i = 0; i < q; i++) {
		if(queens[i].first == r || queens[i].second == c) return true;
		if(abs(queens[i].first - r) == abs(queens[i].second - c)) return true;
	}
	return false;
}

void recurse(int q) {
	if(q == 8) {
		int tot = 0;
		for(int i = 0; i < 8; i++)
			tot += board[queens[i].first][queens[i].second];
		tmax = max(tot, tmax);
		return;
	}

	int sum = 0;
	int cmax = 0;
	for(int r = 0; r < 8; r++) {
		if(!conflict(q, r, q)) {
			queens[q] = make_pair(r, q);
			recurse(q + 1);
		}
	}
}

int main() {
	scanf("%d", &k);
	while(k--) {
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				scanf("%d", &board[i][j]);
		tmax = 0;
		recurse(0);
		printf("%5d\n", tmax);
	}
}
