#include <cstdio>
#include <cmath>

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);

    long long ans = floor(((double)N * (N+1))/6.0);
    printf("%lld\n", ans);
  }
  return 0;
}
