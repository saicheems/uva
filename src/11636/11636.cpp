/*
 * Sai Cheemalapati
 * UVa 11636: Hello world!
 */

#include<cstdio>

int main() {
        int n;
        for(int T = 1;; T++) {
                scanf("%d", &n);
                if (n < -1) break;

                n -= 1;
                // Number of moves in total.
                int moves = 0;
                while (n > 0) {
                        n = n >> 1;
                        moves += 1;
                }
                printf("Case %d: %d\n", T, moves);
        }
}
