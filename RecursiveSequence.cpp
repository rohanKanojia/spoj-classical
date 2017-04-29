#include <cstdio>
#include <cstring>
using namespace std;

#define SIZE 10
#define MOD 1000000000

void setZero(long long aMatrix[SIZE][SIZE]) {
  for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < SIZE; j++)
      aMatrix[i][j] = 0;
}

void initializeIdentityMatrix(long long aMatrix[SIZE][SIZE]) {
  setZero(aMatrix);
  for(int i = 0; i < SIZE; i++)
    aMatrix[i][i] = 1;
}

void matrixCopy(long long dest[SIZE][SIZE], long long src[SIZE][SIZE]) {
  for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < SIZE; j++)
      dest[i][j] = src[i][j];
}

void matrixMultiply(long long res[SIZE][SIZE], long long a[SIZE][SIZE], long long b[SIZE][SIZE], int N) {
  setZero(res);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
}

void matrixExponentiation(long long M1[SIZE][SIZE], int N, int K) {
  long long res[SIZE][SIZE], P[SIZE][SIZE], aux[SIZE][SIZE];
  initializeIdentityMatrix(res);
  if(N == 0) {
    matrixCopy(M1, res);
  }
  else if(N == 1) {
    return;
  }
  else {
    matrixCopy(P, M1);
    
    while(N) {
      if(N & 1) {
        matrixCopy(aux, res);
        matrixMultiply(res, aux, P, K);
      }

      N >>= 1;
      matrixCopy(aux, P);
      matrixMultiply(P, aux, aux, K);
    }
    matrixCopy(M1, res);
  }
}

int main() {
  int T, b[SIZE], c[SIZE];
  long long M1[SIZE][SIZE];
  scanf("%d", &T);

  while(T--) {
    int K, N;
    scanf("%d", &K);

    for(int i = 0; i < K; i++)
      scanf("%d", &b[i]);
    for(int i = 0; i < K; i++)
      b[i] %= MOD;
    for(int i = 0; i < K; i++)
      scanf("%d", &c[i]);

    scanf("%d", &N);
    N--;
    if(N < K)
      printf("%d\n", b[N]);
    else {
      setZero(M1);

      for(int i = 0; i < K; i++)
        M1[0][i] = c[i];
      for(int i = 1; i < K; i++)
        M1[i][i-1] = 1;

      matrixExponentiation(M1, N-K+1, K);

      long long ans = 0;
      for(int i = 0; i < K; i++) 
        ans = (ans + M1[0][i] * b[K-1-i]) % MOD;

      printf("%lld\n", ans);
    }
  }
  return 0;
}
