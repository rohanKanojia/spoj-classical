#include <iostream>
#include <cmath>
using namespace std;

long long modularExponent(long long a, long long b, long long N) {
  long long res = 1;

  while(b) {
    if(b&1) {
      res = (res * a) % N;
    }
    b >>= 1;
    // double the exponents
    a = (a * a) % N;
  }
  return res;
}

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long N, K;
    cin >> N >> K;

    cout << modularExponent(N, K, 10) << endl;
  }

  return 0;
}
