#include <cstdio>

// http://math.stackexchange.com/questions/1230223/finding-sum-k-1na-k-knowing-that-a-1-2a-2-ka-k-frack1k2
int main() {
  long long T;
  scanf("%lld", &T);
  while(T--) {
    long long N;
    scanf("%lld", &N);

    double ans = 3./4.0 - (1. / (2*(N+1) * (N+2)));
    printf("%.11f\n", ans);
  }
  return 0;
}
