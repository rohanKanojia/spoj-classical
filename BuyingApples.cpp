#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int dp[1001], price[1001];
int getMinimumMoney(int price[], int N, int K) {
  dp[0] = 0;

  for(int i = 1; i <= K; i++) {
    int minVal = INT_MAX;
    for(int j = 0; j < i; j++) {
      if(i-j-1 >= 0 && dp[i-j-1] != -1 && price[j] != -1)
        minVal = std::min(minVal, price[j] + dp[i-j-1]);
    }
    dp[i] = minVal == INT_MAX ? -1 : minVal;
  }
  return dp[K];
}

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N, K;
    scanf("%d%d", &N, &K);

    for(int i = 0; i < K; i++)
      scanf("%d", &price[i]);

    printf("%d\n", getMinimumMoney(price, N, K));
  }
  return 0;
}
