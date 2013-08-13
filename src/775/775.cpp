/*
 * Sai Cheemalapati
 * UVA 775: Hamiltonian cycle
 *
 */

#include<cstdio>
#include<cstring>
#include<map>
#include<vector>

using namespace std;

int n, a, b;
bool done;
char line[100];
vector<vector<int> > adj;
vector<int> moves;
map<int, bool> vis;

bool search(int v, int m) {
	vis[v] = true;
	moves.push_back(v);
	if(done) return true;
	bool ans = false;
	for(int i = 0; i < adj[v].size(); i++)
		if(!vis[adj[v][i]] || m + 1 == n && adj[v][i] == 0) {
			if(m + 1 == n && adj[v][i] == 0) {
				for(int i = 0; i < moves.size(); i++) {
					printf("%d ", moves[i] + 1);
				}
				printf("1\n");
				return done = true;
			}
			ans = ans || search(adj[v][i], m + 1);
		}
	vis[v] = false;
	moves.pop_back();
	return ans;
}

int main() {
	for(;;) {
		if(scanf("%d\n", &n) == -1) break;
		adj.clear();
		vis.clear();
		moves.clear();
		adj.resize(n);
		while(gets(line), strcmp(line, "%")) {
			sscanf(line, "%d %d", &a, &b);
			adj[a - 1].push_back(b - 1); adj[b - 1].push_back(a - 1);
		}
		done = false;
		if(!search(0, 0))
			printf("N\n");
	}
}
