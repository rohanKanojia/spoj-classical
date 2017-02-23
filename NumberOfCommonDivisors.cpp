#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    long long g = std::__gcd(a, b);

    long long nFactors = 0;
    for(long long i = 1; i*i <= g; i++) {
      if(g % i == 0) {
        nFactors += 2; // Factors of a number occur in pairs
        if(i == g/i)   // Say if i is a factor, then so is N/i.
          nFactors--;
      }
    }
    printf("%lld\n", nFactors);
  }
  return 0;
}
