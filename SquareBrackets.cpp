#include <iostream>
#include <vector>
using namespace std;

int dp[40][40];

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N, K;
    cin >> N >> K;
    vector<bool> isOpeningBrace(50, false);
    for(int i = 0; i < K; i++) {
      int tmp;
      cin >> tmp;
      isOpeningBrace[tmp] = true;
    }

    for(int i = 1; i <= 2*N; i++) {
      for(int j = 0; j <= i; j++) {
        if(i == 1 && j == 1)
          dp[i][j] = 1;
        else if(i == 1 && j > 1)
          dp[i][j] = 0;
        else {
          if(isOpeningBrace[i]) {
            dp[i][j] = j == 0 ? 0 : dp[i-1][j-1];
          }
          else {
            dp[i][j] = dp[i-1][j+1];
            if(j > 0) 
              dp[i][j] += dp[i-1][j-1];
          }
        }
      }
    }

    cout << dp[2*N][0] << endl;
  }
  return 0;
}
