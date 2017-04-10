#include <iostream>
#include <vector>
using namespace std;

#define INF 100000

int main() {
  while(true) {
    int N, T;
    cin >> N >> T;
    if(!N && !T) break;
    
    vector<vector<int> > tolls(N, vector<int>(N));
    vector<vector<int> > times(N, vector<int>(N));
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        cin >> times[i][j];

    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        cin >> tolls[i][j];

    vector<vector<int> > dp(N+1, vector<int>(T+1, INF));
    dp[0][0] = 0;

    int travelTime = -1;
    for(int k = 1; k <= T; k++) {
      for(int i = 0; i < N; i++) {
        dp[i][k] = dp[i][k-1];
        for(int j = 0; j < N; j++) {
          if(k >= times[j][i])
            dp[i][k] = std::min(dp[i][k], dp[j][k-times[j][i]] + tolls[j][i]);
        }
      }
      if(dp[N-1][k] != dp[N-1][k-1])
        travelTime = k;
    }

    cout << dp[N-1][travelTime] << " " << travelTime << endl;
  }
  return 0;
}
