#include <cstdio>

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);

    if(N & (N-1)) {
      long long ans = 1, left, right;

      for(left = 1; ans < N; ans <<= 1, left++);
      for(right = 0; (N & (1<<right)) == 0; right++);

      printf("%lld %lld\n", ans, left-right-1);
    }
    else
      printf("%lld 0\n", N);

  }
  return 0;
}
