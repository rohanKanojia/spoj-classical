#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[250][250];
long long getRockLength(string& rock, long long start, long long end) {
  long long ones = 0, zeroes = 0, i;

  if(start > end)
    return 0;
  else if(start == end) 
    return rock[start] - '0';
  else if(dp[start][end] == -1) {
    for(i = start; i <= end; i++) {
      ones += (rock[i] == '1');
      zeroes += (rock[i] == '0');
    }

    if(ones > zeroes) 
      dp[start][end] = ones + zeroes;
    else {
      long long maxVal = 0;

      for(i = start; i <= end; i++) {
        long long left = (i == end) ? 0 : getRockLength(rock, start, i);
        long long right = (i == start) ? 0 : getRockLength(rock, i+1, end);

        maxVal = std::max(maxVal, left+right);
      }
      dp[start][end] = maxVal;
    }
  }
  return dp[start][end];
}

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N;
    string rock;
    cin >> N >> rock;
    
    for(long long i = 0; i <= N; i++)
      for(long long j = 0; j <= N; j++)
        dp[i][j] = -1;
    long long ans = getRockLength(rock, 0, N-1);
    cout << ans << endl;
  }
  return 0;
}
