#include<climits>
#include<cstdint>
#include<cstdio>

int main() {
  int n;
  scanf("%d", &n);

  while (n--) {
    int a;
    int b;
    int c;
    scanf("%d %d %d", &a, &b, &c);

    int64_t values[21][21][21] = { 0 };
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) {
        for (int k = 1; k <= c; k++) {
           scanf("%ld", &values[i][j][k]);
	}
      }
    }

    int64_t sums[21][21][21] = { 0 };
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) {
        for (int k = 1; k <= c; k++) {
          sums[i][j][k] += sums[i - 1][j][k];
          sums[i][j][k] += sums[i][j - 1][k];
          sums[i][j][k] += sums[i][j][k - 1];
          sums[i][j][k] -= sums[i - 1][j - 1][k];
          sums[i][j][k] -= sums[i][j - 1][k - 1];
          sums[i][j][k] -= sums[i - 1][j][k - 1];
          sums[i][j][k] += sums[i - 1][j - 1][k - 1];
	  sums[i][j][k] += values[i][j][k];
	}
      }
    }

    int64_t max = LLONG_MIN;
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) {
        for (int k = 1; k <= c; k++) {
          for (int p = i; p <= a; p++) {
            for (int q = j; q <= b; q++) {
              for (int r = k; r <= c; r++) {
                int64_t sum = sums[p][q][r];
                sum -= sums[i - 1][q][r];
                sum -= sums[p][j - 1][r];
                sum -= sums[p][q][k - 1];
                sum += sums[i - 1][j - 1][r];
                sum += sums[p][j - 1][k - 1];
                sum += sums[i - 1][q][k - 1];
                sum -= sums[i - 1][j - 1][k - 1];
		if (sum > max) {
                  max = sum;
		}
              }
            }
	  }
	}
      }
    }
    printf("%ld\n", max);
    if (n > 0) {
      printf("\n");
    }
  }
}
