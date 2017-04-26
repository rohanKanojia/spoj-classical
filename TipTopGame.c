#include <stdio.h>
#include <math.h>

int main() {
  long long T, nCase = 1;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);
    long long sqN = sqrt(N);
    printf("Case %lld: ", nCase++);
    if(sqN*sqN == N)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
