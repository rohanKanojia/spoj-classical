#include <cstdio>

int main() {
  long long N;
  while(true) {
    scanf("%lld", &N);
    if(N == 0)
      break;
    N++;
    long long ans = (3*N*N - N)/2;
    printf("%lld\n", ans);
  }
  return 0;
}
