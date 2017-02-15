#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(long long x) {
  long long sqrtX = sqrt(x);
  return sqrtX*sqrtX == x;
}

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long num;
    cin >> num;

    long long sqrtN = sqrt(num);
    bool bTwoSquares = false;
    for(long long i = 0; i <= sqrtN; i++) {
      if(isPerfectSquare(num-i*i)) {
        bTwoSquares = true;
        break;
      }
    }

    cout << (bTwoSquares ? "Yes" : "No") << endl;
  }
  return 0;
}
