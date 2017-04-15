#include <cstdio>

long long sumDigits(long long N) {
  long long sum = 0;
  while(N > 0) {
    sum += (N%10);
    N /= 10;
  }
  return sum;
}

int main() {
  long long T;
  scanf("%lld", &T);
  while(T--) {
    long long N;
    scanf("%lld", &N);

    while(N%sumDigits(N) != 0) 
      N++;
    printf("%lld\n", N);
  }
  return 0;
}
