#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define M 1000000007
#define MOD(x) (x%M + M)%M

int main() {
  long long T;
  cin >> T;

  while(T--) {
    string ss;
    cin >> ss;

    vector<long long> dp(ss.length()+1), last(256, -1);
    dp[0] = 1;

    for(long long i = 1; i <= ss.length(); i++) {
      dp[i] = MOD(2*dp[i-1]);
      if(last[ss[i-1]] != -1) {
        dp[i] -= dp[last[ss[i-1]]];
        if(dp[i] < 0)
          dp[i] += M;
      }
      last[ss[i-1]] = i-1;
    }

    cout << dp[ss.length()] << endl;
  }
  return 0;
}
