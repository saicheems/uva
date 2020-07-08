#include<climits>
#include<cstdio>
#include<map>
#include<string.h>

using namespace std;

int m;
int s;
int sSq;
int convValue[41];
int itValue[41];
int memo[301 * 301][301];

int solve(int numCoins, int convSum, int itSum) {
  int eModulusSq = convSum * convSum + itSum * itSum;
  if (eModulusSq == sSq) {
    return numCoins;
  } else if (eModulusSq > sSq) {
    return INT_MAX;
  }
  if (memo[eModulusSq][numCoins] != 0) {
    return memo[eModulusSq][numCoins];
  }
  int result = INT_MAX;
  for (int i = 0; i < m; i++) {
    int tmpResult = solve(numCoins + 1, convSum + convValue[i], itSum + itValue[i]);
    if (tmpResult < result) {
      result = tmpResult;
    }
  }
  memo[eModulusSq][numCoins] = result;
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &m);
    scanf("%d", &s);
    sSq = s * s;
    memset(convValue, 0, sizeof(convValue));
    memset(itValue, 0, sizeof(itValue));
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < m; i++) {
      scanf("%d %d", &convValue[i], &itValue[i]);
    }
    int numCoins = solve(0, 0, 0);
    if (numCoins == INT_MAX) {
      printf("not possible\n");
    } else {
      printf("%d\n", numCoins);
    }
  }
}
