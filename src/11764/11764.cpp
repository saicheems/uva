/*
 * UVa 11764: Jumping Mario
 * Sai Cheemalapati
 *
 */

#include <cstdio>

int main() {
    int T, N;

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);

        int h = 0, l = 0, prev = 0, cur = 0;
        scanf("%d", &prev);
        for (int i = 1; i < N; i++) {
            scanf("%d", &cur);
            if(cur > prev) h++;
            if(cur < prev) l++;
            prev = cur;
        }

        printf("Case %d: %d %d\n", t, h, l);
    }
}
