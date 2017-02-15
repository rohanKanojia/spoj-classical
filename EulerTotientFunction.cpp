#include <cstdio>
using namespace std;

long long eulerTotient(long long N) {
  double res = N;

  for(long long j = 2; j*j <= N; j++) {
    if(N%j == 0) {
      while(N%j == 0)
        N /= j;
      res = res * (1.0 - 1.0/(double)j);
    }
  }

  if(N > 1)
    res *= (1.0 - (1.0/(double)N));

  return res;
}

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);
    printf("%lld\n", eulerTotient(N));
  }
  return 0;
}
