#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long dp[6100][6100];

long long lowestCommonSubsequence(string a, string b);

int main() {
  long long T;
  cin >> T;
  while(T--) {
    string ss;
    cin >> ss;
    
    string rev(ss);
    std::reverse(rev.begin(), rev.end());
    cout << ss.length() - lowestCommonSubsequence(ss, rev) << endl;
  }
  return 0;
}

long long lowestCommonSubsequence(string a, string b) {
  long long N = a.length(), M = b.length();

  for(long long i = 0; i <= N; i++) {
    for(long long j = 0; j <= M; j++) {
      if(i == 0 || j == 0)
        dp[i][j] = 0;
      else if(a[i-1] == b[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      }
      else {
        dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
      }
    }
  }

  return dp[N][M];
}
