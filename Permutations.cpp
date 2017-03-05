#include <cstdio>
#include <vector>
using namespace std;

int inv[15][100];
int countInv(int N, int K) {
  if(N == 0) return 0;
  if(K == 0) return 1;

  if(inv[N][K] == -1) {
    int ans = 0;
    for(int i = 0; i < N && K-i >= 0; i++)
      ans += countInv(N-1, K-i);
    inv[N][K] = ans;
  }
  return inv[N][K];
}

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N+1; i++)
      for(int j = 0; j < K+1; j++)
        inv[i][j] = -1;

    printf("%d\n", countInv(N, K));
  }
  return 0;
}
