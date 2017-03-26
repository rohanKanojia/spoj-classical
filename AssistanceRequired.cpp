#include <iostream>
#include <vector>
using namespace std;

void precompute(vector<int>& primes, vector<int>& isPrime) {
  isPrime[1] = isPrime[0] = false;
  for(int i = 2; i < isPrime.size(); i++) {
    if(isPrime[i] == true) {
      int x = 0;
      for(int j = i+1; j < isPrime.size(); j++) {
        if(isPrime[j])
          x++;
        if(x == i) {
          isPrime[j] = false;
          x = 0;
        }
      }
    }
  }
  for(int i = 0; i < isPrime.size(); i++) {
    if(isPrime[i]) 
      primes.push_back(i);
  }
}

int main() {
  vector<int> primes, isPrime(40000, true);

  precompute(primes, isPrime);
  while(true) {
    long long N;
    cin >> N;
    if(N == 0)
      break;

    cout << primes[N-1] << endl;
  }
  return 0;
}
