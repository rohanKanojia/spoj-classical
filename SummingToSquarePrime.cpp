#include <cstdio>
#include <algorithm>
#include <vector>

#define SIZE 8000
std::vector<int> squarePrime;
bool isPrime[SIZE], isSquare[SIZE];
int dp[SIZE][4];

void precompute(int N) {
  std::fill(isPrime, isPrime+SIZE, true);
  std::fill(isSquare, isSquare+SIZE, false);

  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i < SIZE; i++) {
    if(isPrime[i]) {
      for(int j = i*i; j < SIZE; j += i)
        isPrime[j] = false;
    }
  }

  for(int i = 1; i*i < SIZE; i++)
    isSquare[i*i] = true;

  squarePrime.push_back(2);
  for(int i = 3; i < SIZE; i += 2) {
    if(isPrime[i]) {
      bool bSquarePrime = false;

      for(int j = 1; j*j * 2 <= i; j++) {
        if(isSquare[i - j*j]) {
          bSquarePrime = true;
          break;
        }
      }

      if(bSquarePrime)
        squarePrime.push_back(i);
    }
  }
}

int main() {
  int T;
  precompute(SIZE);
  scanf("%d", &T);

  // Now calculating the dp matrix
  for(int i = 0; i < SIZE; i++)
    dp[i][1] = 1;
  dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;

  for(int k = 2; k < 4; k++) {
    for(int i = 1; i < SIZE; i++) {
      dp[i][k] = dp[i][k-1];
      if(i >= k)
        dp[i][k] += dp[i-k][k];
    }
  }

  while(T--) {
    int N, K;
    scanf("%d%d", &N, &K);
    printf("%d\n", dp[squarePrime[N-1]][K]);
  }

  return 0;
}
