/*
 * Sai Cheemalapati
 * UVA 103: Stacking boxes
 *
 */

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;
vector<vector<int> > boxes;
vector<pair<int, int> > edges;
int inf = 1000, nil = -1000;
vector<int> path;

bool fits(vector<int> a, vector<int> b) {
	// returns true if a fits within b
	for(int i = 0; i < a.size(); i++) {
		if(a[i] >= b[i])
			return false;
	}
	return true;
}

bool print_path(int pi[], int s, int v) {
	if(v == s) {
	} else {
		print_path(pi, s, pi[v]);
		path.push_back(v);
	}
}

int main() {
	while(scanf("%d %d", &N, &K) == 2) {
		// init
		boxes.clear();
		boxes.resize(N);
		edges.clear();
		path.clear();

		for(int n = 0; n < N; n++) {
			boxes[n].resize(K);
			for(int k = 0; k < K; k++) {
				scanf("%d", &boxes[n][k]);
			}
			sort(boxes[n].begin(), boxes[n].end());
		}

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				// if it fits inside
				if(fits(boxes[i], boxes[j]))
					edges.push_back(make_pair(i, j));
			}
		}
		// add source nodes
		for(int i = 0; i < N; i++) {
			edges.push_back(make_pair(N, i));
		}

		int d[N + 1];
		int pi[N + 1];

		// init single source
		for(int v = 0; v < N; v++) {
			d[v] = inf;
			pi[v] = nil;
		}
		d[N] = 0;

		for(int i = 0; i < N + 1; i++) {
			for(int e = 0; e < edges.size(); e++) {
				if(d[edges[e].second] > d[edges[e].first] - 1) {
					d[edges[e].second] = d[edges[e].first] - 1;
					pi[edges[e].second] = edges[e].first;
				}
			}
		}

		int min = 1000;
		int min_index = 0;
		for(int i = 0; i < N + 1; i++) {
			if(d[i] < min) {
				min = d[i];
				min_index = i;
			}
		}

		print_path(pi, N, min_index);
		printf("%d\n%d", path.size(), path[0] + 1);
		for(int i = 1; i < path.size(); i++) {
			printf(" %d", path[i] + 1);
		}
		printf("\n");
	}
}
