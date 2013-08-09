/*
 * Sai Cheemalapati
 * UVA 487: Boggle blitz
 *
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>

using namespace std;

int T, N;
int x[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 }, y[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
char inp[100], board[100][100];
bool vis[100][100];
set<string> words[20];

void boggle(int r, int c, string word) {
	word += board[r][c];
	if(word.length() >= 3) words[word.length()].insert(word);

	for(int i = 0; i < 9; i++) {
		int nr = r + x[i]; int nc = c + y[i];
		if(nr >= 0 && nr < N && nc >= 0 && nc < N && board[nr][nc] > word[word.length() - 1] && !vis[nr][nc]) {
			vis[nr][nc] = true;
			boggle(nr, nc, word);
			vis[nr][nc] = false;
		}
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d\n", &N);
		for(int i = 0; i < N; i++) {
			gets(inp);
			strcpy(board[i], inp);
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				boggle(i, j, "");
		for(int i = 3; words[i].size() != 0; i++) {
			for(set<string>::iterator iter = words[i].begin(); iter != words[i].end(); ++iter)
				cout << *iter << endl;
			words[i].clear();
		}
		if(T) printf("\n");
	}
}
