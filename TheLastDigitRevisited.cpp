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
    a = (a * a) % N;
  }
  return res;
}

int main() {
  long long T;
  cin >> T;

  while(T--) {
    string aStr;
    long long b;
    cin >> aStr >> b;

    long long a = aStr[aStr.length()-1] - '0';

    cout << modularExponent(a, b, 10) << endl;
  }
  return 0;
}
