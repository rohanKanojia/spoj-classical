#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N;
    cin >> N;

    long long sumGP = 0, k = 2, digitLen = 0; // Since the gp of the digit length is 2, 4, 8..
    do {
      sumGP += pow(2, ++digitLen);
    } while(sumGP < N);

    long long offset = sumGP - N;

    for(long long i = digitLen-1; i >= 0; i--) {
      if(offset & (1<<i))
        cout << "5";
      else
        cout << "6";
    }
    cout << endl;
  }
  return 0;
}
