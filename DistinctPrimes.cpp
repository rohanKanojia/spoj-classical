#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int SIZE = 3000;
void precomputeSmartNumbers(vector<int>& smartNumbers, int SIZE);

int main() {
  int T;
  vector<int> smartNumbers;
  precomputeSmartNumbers(smartNumbers, SIZE);
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
    cout << smartNumbers[N-1] << endl;
  }
  return 0;
}

void precomputeSmartNumbers(vector<int>& smartNumbers, int SIZE) {
  vector<int> primes(SIZE, 0);

  primes[0] = primes[1] = 0;
  for(int i = 2; i < SIZE; i++) {
    if(primes[i] == 0) {
      primes[i] = 1;
      for(int j = i*2; j < SIZE; j += i) {
        primes[j]--;

        if(primes[j] == -3)
          smartNumbers.push_back(j);
      }
    }
  }
  sort(smartNumbers.begin(), smartNumbers.end());
}
