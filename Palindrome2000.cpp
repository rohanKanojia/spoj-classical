#include <cstdio>
#include <algorithm>
using namespace std;

#define SIZE 5001
char str[SIZE];
int dp[SIZE][SIZE];

int main() {
  int N;
  scanf("%d%s", &N, str);

  for(int i = N-1; i >= 0; i--)
    dp[i][i] = 0;

  for(int i = N-1; i >= 0; i--) {
    for(int j = i+1; j < N; j++) {
      if(str[i] == str[j])
        dp[i][j] = dp[i+1][j-1];
      else
        dp[i][j] = 1 + std::min(dp[i+1][j], dp[i][j-1]);
    }
  }

  printf("%d\n", dp[0][N-1]);
  return 0;
}
