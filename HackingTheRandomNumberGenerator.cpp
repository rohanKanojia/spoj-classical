#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long N, K;
  scanf("%lld%lld", &N, &K);
  vector<long long> arr(N);
  for(long long i = 0; i < N; i++)
    scanf("%lld", &arr[i]);

  std::sort(arr.begin(), arr.end());
  long long ans = 0;
  for(long long i = 0; i < N; i++) {
    if(std::binary_search(arr.begin()+i+1, arr.end(), arr[i]+K))
      ans++;
  }

  printf("%lld\n", ans);
  return 0;
}
