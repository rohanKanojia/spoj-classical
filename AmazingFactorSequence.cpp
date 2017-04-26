#include <cstdio>
#include <algorithm>
using namespace std;

#define SIZE 1000000
long long F[SIZE], A[SIZE];

void precompute() {
  std::fill(F, F+SIZE, 1);
  for(long long i = 2; i < SIZE; i++) {
    for(long long j = 2; j*i < SIZE; j++)
      F[j*i] += i;
  }

  A[0] = A[1] = 0;
  for(long long i = 2; i < SIZE; i++)
    A[i] = A[i-1] + F[i];
}

int main() {
  int t;
  scanf("%d", &t);

  precompute();
  while(t--) {
    long long N;
    scanf("%lld", &N);
    printf("%lld\n", A[N]);
  }
  return 0;
}
