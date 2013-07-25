/*
 * Sai Cheemalapati
 * UVA 341: Non-stop travel
 *
 */

#include<cstdio>
#include<vector>

using namespace std;

int N, m, v, w, a, b;
vector<pair<pair<int, int>, int> > e;
int d[20], pi[20];

void print_path(int s, int v) {
	if(v == s)
		printf("%d", s + 1);
	else {
		print_path(s, pi[v]);
		printf(" %d", v + 1);
	}
}

int main() {
	for(int T = 1;; T++) {
		scanf("%d", &N);
		if(N == 0) break;
		e.clear();
		for(int u = 0; u < N; u++) {
			scanf("%d", &m);
			for(int j = 0; j < m; j++) {
				scanf("%d %d", &v, &w);
				e.push_back(make_pair(make_pair(u, v - 1), w));
			}
		}
		scanf("%d %d", &a, &b);

		for(int i = 0; i < N; i++)
			d[i] = 100000, pi[i] = -1;
		d[a - 1] = 0;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < e.size(); j++)
				if(d[e[j].first.second] > d[e[j].first.first] + e[j].second) {
					d[e[j].first.second] = d[e[j].first.first] + e[j].second;
					pi[e[j].first.second] = e[j].first.first;
				}

		printf("Case %d: Path = ", T);
		print_path(a - 1, b - 1);
		printf("; %d second delay\n", d[b - 1]);
	}
}
