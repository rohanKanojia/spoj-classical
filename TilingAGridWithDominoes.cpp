/*
http://math.stackexchange.com/questions/664113/count-the-ways-to-fill-a-4-times-n-board-with-dominoes?newreg=465d0246ee4e4043b5f2ef4df6310693
*/

#include <cstdio>
#define SIZE 1001

int main() {
  int dp[SIZE], T, nCase = 1;
  dp[0] = dp[1] = 1;
  dp[2] = 5;
  dp[3] = 11;
  for(int i = 4; i < SIZE; i++)
    dp[i] = dp[i-1] + 5*dp[i-2] + dp[i-3] - dp[i-4];

  scanf("%d", &T);
  while(T--) {
    int N;
    scanf("%d", &N);
    printf("%d %d\n", nCase++, dp[N]);
  }
  return 0;
}
