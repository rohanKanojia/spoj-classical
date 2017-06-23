#include <cstdio>

long long res[1000001], phi[1000001];

void precompute(int N) {
  for(int i = 1; i <= N; i++)
    phi[i] = i;
  for(int i = 2; i <= N; i++) {
    if(phi[i] == i) {
      for(int j = i; j <= N; j += i) 
        phi[j] = (phi[j]/i) * (i-1);
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j += i)
      res[j] += (i * phi[i]);
  }
}

int main() {
  precompute(1000000);
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);

    long long ans = ((res[N] + 1) * N)/2;
    printf("%lld\n", ans);
  }
  return 0;
}
