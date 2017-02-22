#include <cstdio>
#include <algorithm>

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long a, b;
    scanf("%lld%lld", &a, &b);

    // A * x - B * y = 0 == A/B = y/x
    long long commonDivisor = std::__gcd(b, a);
    printf("%lld %lld\n", b/commonDivisor, a/commonDivisor);
  }
  return 0;
}
