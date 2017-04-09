#include <iostream>
using namespace std;

int main() {
  long long T, N;
  cin >> T;

  while(T--) {
    cin >> N;
    long long nOdd = (N-1)/2;
    cout << (nOdd * nOdd) % N<< endl;
  }
  return 0;
}
