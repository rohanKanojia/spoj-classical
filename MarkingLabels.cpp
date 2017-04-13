#include <cstdio>

int main() {
  int nCase = 1;
  while(true) {
    int N;
    scanf("%d", &N);
    if(N == 0) break;
    
    int ans = 1;
    for(int i = 0; i < N-2; i++)
      ans *= N;
    printf("Case %d, N = %d, # of different labelings = %d\n", nCase++, N, ans);
  }
  return 0;
}
