#include <cstdio>
#include <algorithm>

int yeye[509][509], blog[509][509];
int dp[509][509];

int main() {
  int R, C;
  while(true) {
    scanf("%d%d", &R, &C);
    if(!R && !C) break;

    for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        scanf("%d", &yeye[i][j]);
        if(j > 0)
          yeye[i][j] += yeye[i][j-1];
      }
    }
    for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        scanf("%d", &blog[i][j]);
        if(i > 0)
          blog[i][j] += blog[i-1][j];
      }
    }

    for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        int elem1 = yeye[i][j];
        int elem2 = blog[i][j];
        if(i > 0)
          elem1 += dp[i-1][j];
        if(j > 0)
          elem2 += dp[i][j-1];
        dp[i][j] = std::max(elem1, elem2);
      }
    }
    printf("%d\n", dp[R-1][C-1]);
  }
  return 0;
}
