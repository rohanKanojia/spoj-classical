#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

long long sumDigits1ToN(long long N) {
  if(N < 10)
    return N*(N+1)/2;

  long long d = log10(N);

  vector<long long> a(d+1);
  a[0] = 0, a[1] = 45;
  for(long long i = 2; i <= d; i++)
    a[i] = a[i-1]*10 + 45 * ceil(pow(10, i-1));

  long long p = ceil(pow(10, d));
  long long msd = N/p;

  return msd*a[d] + (msd*(msd-1)/2)*p +
    msd * (1 + N%p) + sumDigits1ToN(N%p);
}

int main() {
  while(true) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    if(a == -1 && b == -1)
      break;

    long long ans = sumDigits1ToN(b) - sumDigits1ToN(a-1);
    printf("%lld\n", ans);
  }
  return 0;
}
