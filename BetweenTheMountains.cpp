#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long M, N;
    scanf("%lld", &M);
    vector<long long> a(M);
    for(long long i = 0; i < M; i++)
      scanf("%lld", &a[i]);

    scanf("%lld", &N);
    vector<long long> b(N);
    for(long long i = 0; i < N; i++)
      scanf("%lld", &b[i]);

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    long long ans = INT_MAX;
    for(long long i = 0; i < M; i++) 
      for(long long j = 0; j < N; j++)
        ans = std::min(ans, abs(b[j]-a[i])); 
    printf("%lld\n", ans);
  }
  return 0;
}
