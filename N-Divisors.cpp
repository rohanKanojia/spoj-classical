#include <cstdio>
#include <cmath>
using namespace std;

#define SIZE 100001
bool isComposite[SIZE]; 
int primes[SIZE], nLength = 0;

void sieve() {
  primes[nLength++] = 2;
  for(int i = 2; i < SIZE; i++) {
    if(!isComposite[i]) {
      for(int j = 2; j*i < SIZE; j++)
        isComposite[i*j] = true;
    }
  }

  for(int i = 3; i < SIZE; i++)
    if(!isComposite[i])
      primes[nLength++] = i;
}

int main() {
  long long a, b, n, ans = 0;
  sieve();
  
  scanf("%lld%lld%lld", &a, &b, &n);

  for(int i = a; i <= b; i++) {
    int divisors = 1, t = i;
    for(int j = 0; primes[j]*primes[j] <= i && j < nLength; j++) {
      int k;
      for(k =1; t % primes[j] == 0 && t > 1; k++) 
        t = t/primes[j];

      divisors = divisors*k;
      if(t == 1) break;
    }
    if(t > 1) 
      divisors *= 2;
    
   ans += (divisors == n);
  }
  printf("%lld\n", ans);
  return 0;
}
