#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int sum, nCoins;
  scanf("%d%d", &sum, &nCoins);
  
  vector<int> coins(nCoins);
  for(int i = 0; i < nCoins; i++) {
    scanf("%d", &coins[i]);
    if(i > 0)
      coins[i] += coins[i-1];
  }

  vector<bool> dp(sum+1, false);
  dp[0] = true;
  for(int i = 0; i < nCoins; i++)
    for(int j = coins[i]; j <= sum; j++)
      dp[j] = dp[j-coins[i]] || dp[j];

  if(dp[sum])
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
