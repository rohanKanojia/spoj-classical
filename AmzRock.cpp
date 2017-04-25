#include <cstdio>

int main() {
  long long F[45], T, N;
  F[0] = 1;
  F[1] = 2;
  for(int i = 2; i < 45; i++)
    F[i] = F[i-1] + F[i-2];

  scanf("%lld", &T);
  while(T--) {
    scanf("%lld", &N);
    printf("%lld\n", F[N]);
  }
  return 0;
}
