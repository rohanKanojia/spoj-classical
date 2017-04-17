#include <cstdio>
#include <cmath>

int main() {
  int T;
  scanf("%d", &T);

  for(int t = 1; t <= T; t++) {
    long long N, M, K;
    scanf("%lld%lld%lld", &N, &M, &K);

    long long nHand = N*M*K-1;
    long long nKnife = ceil(log(N)/log(2)) + ceil(log(M)/log(2)) + ceil(log(K)/log(2));
    printf("Case #%d: %lld %lld\n", t, nHand, nKnife);
  }
}
