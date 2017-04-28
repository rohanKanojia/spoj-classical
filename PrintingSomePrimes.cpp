#include <cstdio>
#include <vector>
using namespace std; 

#define MAX 100000000
#define LIMIT 10000

int isPrime[MAX>>6];

void bitwiseSieve() {
  long long i, j, k;
  for(i = 3; i < LIMIT; i += 2) {
    if((isPrime[i >> 6] & (1<<((i>>1)&31))) == false) {
      for(j = i*i, k = i<<1; j < MAX; j += k)
        isPrime[j>>6] |= (1 << ((j>>1)&31));
    }
  }

  printf("2\n");
  for(i = 3, k = 2; i < MAX; i += 2) 
    if(!(isPrime[i>>6] & (1<<((i>>1)&31)))) {
      if(k % 100 == 1)
        printf("%lld\n", i);
      k++;
    }
}

int main() {
  bitwiseSieve();
  return 0;
}
