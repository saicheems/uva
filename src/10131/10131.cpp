/*
 * Sai Cheemalapati
 * UVa 10131: Is bigger smarter?
 *
 */

#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

int n, m;
vector<pair<pair<int, int>, int> > ws;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.second > b.first.second;
}

void print_path(int *path, int end) {
    if(end > -1) {
        print_path(path, path[end]);
        printf("%d\n", ws[end].second + 1);
    }
}

int main() {
    for(int i = 0;; i++)
        if(scanf("%d %d", &n, &m) == 2)
            ws.push_back(make_pair(make_pair(n, m), i));
        else
            break;
    sort(ws.begin(), ws.end(), compare);

    // longest increasing subsequence
    int s[1100], path[1100];
    int gmax = 1;
    int end_pos = 0;

    s[0] = 1; path[0] = -1;
    for(int i = 1; i < ws.size(); i++) {
        int lprev = -1;
        s[i] = 1;
        for(int j = 0; j < i; j++) {
            if(ws[j].first.first < ws[i].first.first
                    && ws[j].first.second > ws[i].first.second
                    && s[i] < s[j] + 1) {
                s[i] = s[j] + 1;
                lprev = j;
            }
        }
        path[i] = lprev;
        if(gmax < s[i]) {
            gmax = s[i];
            end_pos = i;
        }
    }

    printf("%d\n", gmax);
    print_path(path, end_pos);
}
