/*
 * UVa 10066: The twin towers
 * Sai Cheemalapati
 *
 */

#include <algorithm>
#include <cstdio>

int lcs(int *A, int *B, int M, int N) {
    int L[M + 1][N + 1];
    int i, j;

    for (i = 0; i <= M; i++) {
        for (j = 0; j <= N; j++) {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (A[i - 1] == B[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[M][N];
}

int main() {
    int M, N, A[110], B[110], L[110][110];
    for (int T = 1;; T++) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;

        for (int i = 0; i < M; i++) scanf("%d", &A[i]);
        for (int i = 0; i < N; i++) scanf("%d", &B[i]);

        printf("Twin Towers #%d\n", T);
        printf("Number of Tiles : %d\n\n", lcs(A, B, M, N));
    }
}
