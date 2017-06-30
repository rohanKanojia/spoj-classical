#include <cstdio>
#include <vector>

int dp[2][2000001];

int knapsackOptimized(std::vector<int>& weight, std::vector<int>& value, int K) {
  for(int i = 1; i <= value.size(); i++) {
    int j = 0;

    if(i%2 != 0) {
      while(++j <= K) {
        if(weight[i-1] <= j)
          dp[1][j] = std::max(value[i-1] + dp[0][j-weight[i-1]], dp[0][j]);
        else
          dp[1][j] = dp[0][j];
      }
    }
    else {
      while(++j <= K) {
        if(weight[i-1] <= j)
          dp[0][j] = std::max(value[i-1] + dp[1][j-weight[i-1]], dp[1][j]);
        else
          dp[0][j] = dp[1][j];
      }
    }
  }

  return dp[weight.size() & 1][K];
}

int main() {
  int K, N;
  scanf("%d%d", &K, &N);

  std::vector<int> weight(N), value(N);
  for(int i = 0; i < N; i++)
    scanf("%d%d", &value[i], &weight[i]);

  printf("%d\n", knapsackOptimized(weight, value, K));
  return 0;
}
