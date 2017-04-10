#include <cstdio>
#include <vector>

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);

    std::vector<long long> arr(N+7, 0), dp(N+7, 0);
    for(int i = 0; i < N; i++)
      scanf("%lld", &arr[i]);

    for(int i = N-1; i >= 0; i--) {
      dp[i] = arr[i] + dp[i+2];

      if(i+1 < N) 
        dp[i] = std::max(dp[i], arr[i] + arr[i+1] + dp[i+4]);
      if(i+2 < N)
        dp[i] = std::max(dp[i], arr[i] + arr[i+1] + arr[i+2] + dp[i+6]);
    }
    printf("%lld\n", dp[0]);
  }
  return 0;
}
