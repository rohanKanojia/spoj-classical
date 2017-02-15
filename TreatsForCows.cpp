#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
  long long N;
  vector<long long> prices;
  cin >> N;

  for(long long i = 0; i < N; i++) {
    long long tmp;
    cin >> tmp;
    prices.push_back(tmp);
  }

  vector<vector<long long> > dp(N+1, vector<long long>(N+1, 0));
  for(long long i = 1; i <= N; i++) {
    dp[i][i] = prices[i-1] * N;
  }

  // filling the array diagonally :
  for(long long i = N-1; i >= 1; i--) {
    for(long long r = i, c = N; r >= 1 && c >= 1; r--, c--) {
      long long age = N-(c-r);
      dp[r][c] = std::max(prices[r-1] * age + dp[r+1][c], prices[c-1] * age + dp[r][c-1]);
    }
  }

  cout << dp[1][N] << endl;

  return 0;
}
