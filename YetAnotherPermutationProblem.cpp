#include <cstdio>
#define MOD 1000000007

long long modularExponent(long long a, long long b, long long N) {
    long long res = 1;

    while(b) {
      if(b&1)
          res = (res * a) % N;

      b >>= 1;
      a = (a*a) % N;
    }
    return res;
}

int main() {
    long long T;
    scanf("%lld", &T);

    while(T--) {
       long long N;
       scanf("%lld", &N);
       
       printf("%lld\n", modularExponent(2, N-1, MOD));    
    }
    return 0;
}
