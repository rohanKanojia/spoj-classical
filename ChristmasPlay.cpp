#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long T;
  scanf("%lld", &T);
  while(T--) {
    long long N, K, ans = 0;
    vector<long long> arr;
    scanf("%lld%lld", &N, &K);

    for(long long i = 0; i < N; i++) {
      long long tmp;
      scanf("%lld", &tmp);
      arr.push_back(tmp);
    }
    std::sort(arr.begin(), arr.end());
    
    ans = arr[K-1] - arr[0];

    for(long long i = 1; i + K <= N; i++) 
      ans = std::min(ans, arr[i+K-1] - arr[i]);
    printf("%lld\n", ans);
  }
  return 0;
}
