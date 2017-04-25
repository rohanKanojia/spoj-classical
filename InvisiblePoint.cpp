#include <cstdio>

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);

    long long ans = 0, a = 1;
    for(; a < N; a *= 2)
      ans++;
    printf("%lld\n", ans+1);
  }
  return 0;
}
