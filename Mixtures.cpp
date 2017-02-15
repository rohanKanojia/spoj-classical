#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long getMinimumSmoke(vector<long long>& colors) {
  long long N = colors.size();
  vector<vector<long long> > dp(N+1, vector<long long>(N+1));
  vector<vector<long long> > color(N+1, vector<long long>(N+1));

  for(long long i = 1; i < N+1; i++) {
    dp[i][i] = 0;
    color[i][i] = colors[i-1];
  }

  for(long long l = 2; l <= N; l++) {
    for(long long i = 1; i <= N-l+1; i++) {
      long long j = i+l-1;
      dp[i][j] = INT_MAX;
      for(long long k = i; k <= j-1; k++) {
        long long tmp = dp[i][k] + dp[k+1][j] + color[i][k] * color[k+1][j];
        
        if(tmp < dp[i][j]) {
          color[i][j] = (color[i][k] + color[k+1][j])%100;
          dp[i][j] = tmp;
        }
      }
    }
  }
  return dp[1][N];
}

int main() {
  long long N;
  while(scanf("%lld", &N) > 0) {
    vector<long long> colors(N);

    for(long long i = 0; i < N; i++)
      scanf("%lld", &colors[i]);

    printf("%lld\n", getMinimumSmoke(colors));
  }
  return 0;
}

