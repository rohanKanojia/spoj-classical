#include <cstdio>
#include <cmath>

int main() {
  long long T;
  scanf("%lld", &T);

  for(long long t = 1; t <= T; t++) {
    long long N;
    scanf("%lld", &N);

    long long ans = (-4 + sqrt(16 + 16*N))/4;
    printf("Case %lld: %lld\n", t, ans); 
  }
  return 0;
}
