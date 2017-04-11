#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <algorithm>
using namespace std;

void printFactors(long long N);

int main() {
  while(true) {
    long long N;
    scanf("%lld", &N);
    if(!N) break;

    printFactors(N);
  }
  return 0;
}


void printFactors(long long N) {
  long long n2 = 0, nOthers = 0;
  while(N%2 == 0) {
    n2++;
    N /= 2;
  }
  if(n2 > 0) printf("2^%lld ", n2);

  for(long long i = 3; i <= sqrt(N); i += 2) {
    nOthers = 0;
    while(N%i == 0) {
      N /= i;
      nOthers++;
    }
    if(nOthers > 0) printf("%lld^%lld ", i, nOthers);
  }
  if(N > 2)
    printf("%lld^1 ", N);
  printf("\n");
}
