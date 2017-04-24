#include <cstdio>
using namespace std;

#define MOD 1000000003
long long F[1000010];

void precompute() {
  long long curSum = 0;	
  for(long long i = 1; i <= 1000000; i++) {
    curSum = (curSum + i*i*i) % MOD;
    F[i] = (F[i-1] + curSum) % MOD;
  }
}

int main() {
  int T;
  precompute();
  scanf("%d", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);
    printf("%lld\n", F[N]);
  }
  return 0;
}
