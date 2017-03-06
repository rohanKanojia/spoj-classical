#include <cstdio>
#include <unistd.h>
#include <algorithm>
using namespace std;

long long computeSteps(long long a, long long b, long long K) {
  long long nSteps = 0, A = 0, B = 0;

  while(A != K && B != K) {
    if(A == 0) // Pour
      A = a;
    else if(B == b) // Empty
      B = 0;
    else { // transfer a to b
      B += A;
      A = 0;
      if(B > b) {
        A = B - b;
        B = b;
      }
    }
    nSteps++;
  }

  return nSteps;
}

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long A, B, K, ans;
    bool bPossible = true;
    scanf("%lld%lld%lld", &A, &B, &K);
    if(K > std::max(A, B) || K%std::__gcd(A, B) != 0)
      bPossible = false; 

    if(bPossible) {
      ans = std::min(computeSteps(A, B, K), computeSteps(B, A, K));
    }
    if(bPossible)
      printf("%lld\n", ans);
    else
      printf("-1\n");
  }
  return 0;
}
