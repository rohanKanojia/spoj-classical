#include <cstdio>
#include <vector>
using namespace std;

#define INF 100000

int main() {
  int nTests;
  scanf("%d", &nTests);

  while(nTests--) {
    int N, T;
    scanf("%d%d", &N, &T);

    vector<vector<int> > time(N, vector<int>(N)),
      risk(N, vector<int>(N));

    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        scanf("%d", &time[i][j]);

    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        scanf("%d", &risk[i][j]);
    
    vector<vector<int> > dp(N+1, vector<int>(T+1, INF)); 
    dp[0][0] = 0;

    int travelTime = -1;
    for(int k = 1; k <= T; k++) {
      for(int i = 0; i < N; i++) {
        dp[i][k] = dp[i][k-1];
        for(int j = 0; j < N; j++) {
          if(k >= time[j][i])
            dp[i][k] = std::min(dp[i][k], dp[j][k-time[j][i]] + risk[j][i]);
        }
      }
      if(dp[N-1][k] != dp[N-1][k-1])
        travelTime = k;
    }
    if(travelTime > 0)
      printf("%d %d\n", dp[N-1][travelTime], travelTime);
    else
      printf("%d\n", travelTime);
  }
  return 0;
}
