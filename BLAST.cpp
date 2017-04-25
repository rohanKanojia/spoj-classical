#include <cstdio>
#include <cstring>
#include <algorithm>

#define SIZE 2001
char A[SIZE], B[SIZE];
int dp[SIZE][SIZE], K;

int main() {
  scanf("%s%s%d", A, B, &K);

  int nA = strlen(A), nB = strlen(B);

  for(int i = 0; i <= nA; i++)
    dp[i][0] = K*i;
  for(int i = 0; i <= nB; i++)
    dp[0][i] = K*i;

  for(int i = 1; i <= nA; i++) {
    for(int j = 1; j <= nB; j++) {
      dp[i][j] = std::min(dp[i-1][j-1] + abs(A[i-1] - B[j-1]), std::min(dp[i-1][j], dp[i][j-1]) + K);
    }
  }

  printf("%d\n", dp[nA][nB]);
  return 0;
}
