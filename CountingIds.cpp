#include <cstdio>

#define MOD 1000000007
long long modularPow(long long base, long long exp) {
  long long res = 1;
  while(exp) {
    if(exp & 1)
      res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return res;
}

int main() {
  while(true) {
    long long N, L;
    scanf("%lld%lld", &N, &L);
    if(!N && !L) break;

    long long ans = 0;
    for(long long i = 1; i <= L; i++)
      ans = (ans + modularPow(N, i)) % MOD;

    printf("%lld\n", ans);
  }
  return 0;
}
