#include <iostream>
#include <cmath>
using namespace std;

#define SUM_N(x) ((x * (x+1))/2)

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long N;
    cin >> N;

    long long x = ceil((-1. + sqrt(8 * N + 1))/2);
    long long a = N - (SUM_N(x) - x);
    long long b = x + 1 - a;

    if(x % 2 == 0)
      cout << "TERM " << N << " IS " << a << "/" << b << endl;
    else
      cout << "TERM " << N << " IS " << b << "/" << a << endl;
  }
  return 0;
}
