#include<cstdio>

using namespace std;

bool check(int n, int current_bottom, int last_top, int pieces[7][7]) {
  if (n == 0) {
    return current_bottom == last_top;
  }

  for (int i = 0; i <= 6; i++) {
    if (pieces[current_bottom][i] > 0) {
      // Remove the piece to try from the set of all pieces.
      pieces[current_bottom][i]--;
      pieces[i][current_bottom]--;

      if (check(n - 1, i, last_top, pieces)) {
        return true;
      }

      // If the piece we selected did not lead to a solution, put it back.
      pieces[current_bottom][i]++;
      pieces[i][current_bottom]++;
    }
  }

  return false;
}

int main() {
  while (true) {
    int n;
    int m;
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    scanf("%d", &m);

    // The top value of the first domino and the bottom value of the last
    // domino do not influence the result.
    int first_bottom;
    int last_top;
    scanf("%*d %d", &first_bottom);
    scanf("%d %*d", &last_top);

    int pieces[7][7] = { 0 };
    for (int i = 0; i < m; i++) {
      int top = 0;
      int bottom = 0;
      scanf("%d %d", &top, &bottom);
      pieces[top][bottom]++;
      pieces[bottom][top]++;
    }

    if (check(n, first_bottom, last_top, pieces)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
