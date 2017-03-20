#include <cstdio>
#include <cstring>
using namespace std;

long long dp[100][100][2];

int main() {
  long long T; 
  scanf("%lld", &T);

  while(T--) {
    long long nCase, N, K;
    scanf("%lld%lld%lld", &nCase, &N, &K);

    memset(dp, 0, sizeof(dp));
    dp[1][0][0] = dp[1][0][1] = 1;
    for(int i = 2; i <= N; i++) {
      for(int j = 0; j <= K; j++) {
        dp[i][j][0] = dp[i-1][j][1] + dp[i-1][j][0];
        dp[i][j][1] = dp[i-1][j][0];
        if(j > 0)
          dp[i][j][1] += dp[i-1][j-1][1];
      }
    }
    long long ans = dp[N][K][0] + dp[N][K][1];
    printf("%lld %lld\n", nCase, ans);
  }
  return 0;
}
