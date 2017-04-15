#include <cstdio>

#define SIZE 1000

int main() {
  int zero[SIZE],one[SIZE], two[SIZE];
  int N;
  scanf("%d", &N);

  zero[1] = one[1] = two[1] = 1;
  for(int i = 2; i <= N; i++) {
    zero[i] = zero[i-1] + one[i-1];
    one[i] = zero[i-1] + one[i-1] + two[i-1];
    two[i] = one[i-1] + two[i-1];
  }
  printf("%d\n", zero[N] + one[N] + two[N]);
  return 0;
}
