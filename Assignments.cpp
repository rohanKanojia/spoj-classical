#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N, possibleWays;
    cin >> N;
    vector<vector<long long> > arr(N, vector<long long>(N));
    for(long long i = 0; i < N; i++) {
      for(long long j = 0; j < N; j++)
        cin >> arr[i][j];
    }

    vector<long long> dp((1<<N)+1, 0);
    dp[0] = 1;
    possibleWays = (1<<N)-1;

    for(long long mask = 0; mask < possibleWays; mask++) {
      long long index = __builtin_popcount(mask);

      for(long long i = 0; i < N; i++) {
        if(arr[index][i] == 1 && (mask & (1<<i)) == 0) 
          dp[mask | (1<<i)] += dp[mask];
      }
    }
    cout << dp[possibleWays] << endl;
  }
  return 0;
}
