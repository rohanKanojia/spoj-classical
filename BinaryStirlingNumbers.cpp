#include <cstdio>

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N, K;
    scanf("%lld%lld", &N, &K);
    printf("%lld\n", ((N-K) & (K-1)/2) == 0);
  }
  return 0;
}
