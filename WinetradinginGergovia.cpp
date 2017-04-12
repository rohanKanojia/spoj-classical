#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main() {
  while(true) {
    long long N;
    scanf("%lld", &N);
    if(N == 0) break;
    vector<long long> arr(N);
    for(long long i = 0; i < N; i++)
      scanf("%lld", &arr[i]);

    long long ans = 0;
    for(long long i = 1; i < N; i++) {
      arr[i] = arr[i] + arr[i-1];
      ans += abs(arr[i-1]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
