#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long getMaxCoins(vector<long long>& coins, long long N) {
  if(N <= 0)
    return 0;
  if(N == 1)
    return coins[0];
  vector<long long> dp(N);
  dp[0] = coins[0];  
  dp[1] = std::max(dp[0], coins[1]);

  for(long long i = 2; i < N; i++) {
    dp[i] = std::max(dp[i-1], coins[i] + dp[i-2]);
  }
  return dp[N-1];
}

int main() {
  long long T, nCase = 1;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);

    vector<long long> coins(N);
    for(long long i = 0; i < N; i++)
      scanf("%lld", &coins[i]);

    printf("Case %d: %lld\n", nCase++, getMaxCoins(coins, N));
  }

  return 0;
}

