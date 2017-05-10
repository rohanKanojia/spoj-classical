#include <cstdio>

int main() {
  long long F[14], N, K;
  F[0] = 1;
  for(int i = 1; i <= 13; i++)
    F[i] = F[i-1] * i;

  while(scanf("%d%d", &N, &K) > 0) {
    long long ans = F[N], p;

    for(int i = 0; i < K; i++) {
      scanf("%d", &p);
      ans /= F[p];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
