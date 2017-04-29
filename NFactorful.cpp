#include <cstdio>

#define SIZE 1000010
int divisor[SIZE], F[11][SIZE];

void precompute() {
  for(int i = 2; i < SIZE; i++) {
    if(divisor[i] == 0) {
      for(int j = i; j < SIZE; j += i) 
        divisor[j]++;
    }
  }

  for(int n = 0; n <= 10; n++) {
    for(int i = 1; i < SIZE; i++)
      F[n][i] = F[n][i-1] + (divisor[i] == n);
  }
}

int main() {
  int T;
  scanf("%d", &T);

  precompute();
  while(T--) {
    int n, a, b;
    scanf("%d%d%d", &a, &b, &n);

    printf("%d\n", F[n][b] - F[n][a-1]);
  }
  return 0;
}
