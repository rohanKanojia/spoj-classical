#include <cstdio>
#include <vector>
using namespace std;

#define SIZE 5000001
#define MAX 100000000
#define LIMIT 10000

int isPrime[MAX>>6];
vector<int> primes;

void bitwiseSieve(int N) {
  long long i, j, k;
  for(i = 3; i < LIMIT; i += 2) {
    if((isPrime[i>>6] & (1<<((i>>1)&31))) == false) {
      for(j = i*i, k = i<<1; j < MAX; j += k) {
        isPrime[j>>6] |= (1 << ((j>>1)&31));
      }
    }
  }

  primes.push_back(2);
  for(i = 3; i < MAX && primes.size() < N; i += 2)
    if(!(isPrime[i>>6] & (1<<((i>>1)&31))))
      primes.push_back(i);
}

int main() {
  long long T, N;
  scanf("%lld", &T);

  bitwiseSieve(SIZE);
  while(T--) {
    scanf("%lld", &N);
    printf("%lld\n", primes[N-1]);
  }
  return 0;
}
