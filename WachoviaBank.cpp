#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int K, M;
    scanf("%d%d", &K, &M);

    vector<int> weight, value;
    for(int i = 0; i < M; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      weight.push_back(a);
      value.push_back(b);
    }

    for(int i = 0; i <= M; i++) {
      for(int j = 0; j <= K; j++) {
        if(i == 0 || j == 0)
          dp[i][j] = 0;
        else if(weight[i-1] <= j)
          dp[i][j] = std::max(dp[i-1][j-weight[i-1]] + value[i-1], dp[i-1][j]);
        else
          dp[i][j] = dp[i-1][j];
      }
    }

    printf("Hey stupid robber, you can get %d.\n", dp[M][K]);
  }
  return 0;
}
