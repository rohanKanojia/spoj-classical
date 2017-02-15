#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long T3, TN3, S;
    cin >> T3 >> TN3 >> S;

    long long n, a, d;
    n = (2 * S)/(2 * T3 + (TN3 - T3));
    d = (TN3 - T3)/ (n - 5);
    a = T3 - 2 * d;

    cout << n << endl;

    long long curTerm = a;
    for(long long i = 0; i < n; i++, curTerm += d)
      cout << curTerm << " ";
    cout << endl;
  }
  return 0;
}
