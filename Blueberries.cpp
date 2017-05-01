#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int getMaxBerries(vector<int>& bushes, int i, int nBerries, int N, int K) {
  if(i > N)
    return nBerries;

  if(dp[i][nBerries] == -1) {
    if(bushes[i] + nBerries <= K)
      dp[i][nBerries] = std::max(getMaxBerries(bushes, i+2, nBerries + bushes[i], N, K),
                                 getMaxBerries(bushes, i+1, nBerries, N, K));
    else
      dp[i][nBerries] = getMaxBerries(bushes, i+1, nBerries, N, K);
  }

  return dp[i][nBerries];
}

int main() {
  int T;
  scanf("%d", &T);

  for(int t = 1; t <= T; t++) {
    int N, K;
    scanf("%d%d", &N, &K);
    vector<int> bushes(N);

    for(int i = 0; i < N; i++)
      scanf("%d", &bushes[i]);

    for(int i = 0; i <= N; i++) 
      for(int j = 0; j <= K; j++)
        dp[i][j] = -1; 
    printf("Scenario #%d: %d\n", t, getMaxBerries(bushes, 0, 0, N, K));
  }
  return 0;
}
