#include <iostream>
#include <vector>
using namespace std;

long long dp[100][11];

void precompute() {
  for(int i = 0; i < 10; i++)
    dp[1][i] = 1;
  dp[1][10] = 10;

  for(int i = 2; i < 70; i++) {
    for(int j = 0; j < 10; j++) {
      // Since next possible digits would be >= j
      for(int k = j; k < 10; k++)
        dp[i][j] += dp[i-1][k];
    }

    for(int j = 0; j < 10; j++)
      dp[i][10] += dp[i][j];
  }
}

int main() {
  long long T;
  cin >> T;
  precompute();
  while(T--) {
    long long nCase, N;
    cin >> nCase >> N;

    cout << nCase << " " << dp[N][10] << endl;
  }
  return 0;
}
