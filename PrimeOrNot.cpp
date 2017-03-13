#include <cstdio>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
bool isPrime(ull N, ull k);
bool millerTest(ull d, ull N);
ull modularExp(ull x, ull y, ull p);
ull modularProduct(ull x, ull y, ull N);

int main() {
  ull T;
  scanf("%lld", &T);

  while(T--) {
    ull N;
    scanf("%lld", &N);

    printf("%s\n", (isPrime(N, 4) ? "YES" : "NO"));
  }
  return 0;
}

ull modularExp(ull x, ull y, ull p) {
  ull res = 1;
  x = x % p;

  while(y > 0) {
    if(y & 1)
      res = modularProduct(res, x, p);

    y >>= 1;
    x = modularProduct(x, x, p);
  }
  return res;
}

bool isPrime(ull x, ull k) {
  if(x == 1 || x == 4)
    return false;
  if(x <= 3)
    return true;

  ull d = x-1;
  while(d%2 == 0)
    d /= 2;
  
  for(ull i = 0; i < k; i++)
    if(!millerTest(d, x))
      return false;
  return true;
}

bool millerTest(ull d, ull N) {
  ull a = 2 + rand()%(N-4);
  ull x = modularExp(a, d, N);

  if(x == 1 || x == N-1)
    return true;

  while(d != N-1) {
    x = modularProduct(x, x, N);
    d = 2*d;

    if(x == 1) return false;
    if(x == N-1) return true; // -1 = N-1 mod N
  }
  return false;
}

ull modularProduct(ull x, ull y, ull N) {
  ull res = 0;
  x = x % N;

  while(y) {
    if(y&1)
      res = (res + x)%N;
    x = (2*x)%N;
    y >>= 1;
  }
  return res;
}
