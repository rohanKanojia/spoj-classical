#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 4000020
bool isPrime[SIZE];
void sieveOfEratosethens(vector<int>& primes, int N) {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i*i <= N; i++) {
    if(isPrime[i] == true) {
      for(int j = i*2; j <= N; j += i)
        isPrime[j] = false;
    }
  }

  for(int i = 2; i < SIZE; i++)
    if(isPrime[i])
      primes.push_back(i);
}

int sumOfDivisors(int N, vector<int>& primes) {
  int sum = 1;
  for(int i = 0; primes[i]*primes[i] <= N; i++) {
    int count = 1;
    while(N%primes[i] == 0) {
      count = count*primes[i] + 1;
      N /= primes[i];
    }
    sum = sum * count;
  }
  if(N > 1)
    sum = sum * (1+N);
  return sum;
}

void perfectNumbers(vector<int>& kNumbers, vector<int>& primes) {
  kNumbers.push_back(2);
  for(int i = 1; i*i <= SIZE/4; i++) {
    if(isPrime[sumOfDivisors(i*i, primes)]) 
      kNumbers.push_back(i*i);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  vector<int> primes, kNumbers;

  sieveOfEratosethens(primes, SIZE);
  perfectNumbers(kNumbers, primes);
  while(T--) {
    int a, b;
    scanf("%d%d", &a, &b);

    int aPos = std::lower_bound(kNumbers.begin(), kNumbers.end(), a) - kNumbers.begin();
    int bPos = std::upper_bound(kNumbers.begin(), kNumbers.end(), b) - kNumbers.begin();

    printf("%d\n", bPos-aPos);
  }
  return 0;
}
