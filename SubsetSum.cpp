#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dp[110000][1001];

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N, maxSum = 0;
    scanf("%d", &N);

    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
      scanf("%d", &arr[i]);
      maxSum += arr[i];
    }

    for(int i = 0; i <= maxSum; i++)
      for(int j = 0; j <= N; j++)
        dp[i][j] = 0;

    for(int i = 0; i < N; i++)
      dp[0][i] = 1;

    for(int i = 1; i <= maxSum; i++) {
      for(int j = 1; j <= N; j++) {
        dp[i][j] = dp[i][j-1];
        if(i >= arr[j-1])
          dp[i][j] = dp[i][j] || dp[i-arr[j-1]][j-1];
      }
    }
    int ans = 0;
    for(int j = 1; j <= maxSum; j++)
      if(dp[j][N])
        ans += j;
    printf("%d\n", ans);
  }
  return 0;
}
