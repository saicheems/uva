/*
 * Sai Cheemalapati
 * UVa 305: Joseph
 */

#include <cstdio>

using namespace std;

/*
 * Generated solutions (k, m)
 * 1 2
 * 2 7
 * 3 5
 * 4 30
 * 5 169
 * 6 441
 * 7 1872
 * 8 7632
 * 9 1740
 * 10 93313
 * 11 459901
 * 12 1358657
 * 13 2504881
 * 14 13482720
 */

/* 
 * Returns number of people killed before the first good person is chosen.
 */
int circle (int k, int m) {
  int size = 2 * k;

  int current = (m - 1) % size, i = 0, j = 0;
  for (i = 0; i < 2 * k; i++) {
    if (current < k) break;
    size--;
    current = (current + m - 1) % (size);
  }

  return i;
}

int main () {
  int k;
  int ans[15] = {
    0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740,
    93313, 459901, 1358657, 2504881, 13482720
  };

  // Generates solutions from 1 to 14.
  // I ran this first and added solutions to the program.
  //for (int i = 1; i <= 14; i++) {
  //  for (int j = 1;; j++) {
  //    if (circle(i, j) == i) {
  //      ans[i] = j; 
  //      printf("%d %d\n", i, j);
  //      break;
  //    }
  //  }
  //}

  while (scanf("%d", &k) && k != 0) printf("%d\n", ans[k]);
}
