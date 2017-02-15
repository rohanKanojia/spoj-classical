#include <iostream>
using namespace std;

long long checkHappy(long long N);
long long sumSquares(long long N);

int main() {
  long long N;

  cin >> N;

  cout << checkHappy(N) << endl;
  return 0;
}

long long checkHappy(long long N) {
  long long nSteps = 0;
  bool bCycle = true;

  while(nSteps < 10) {
    long long curSq = sumSquares(N);
    if(curSq == 1) {
      bCycle = false;
      break;
    }
    else {
      N = curSq;
    }
    nSteps++;
  }

  return nSteps < 10 ? nSteps+1 : -1;
}

long long sumSquares(long long N) {
  long long sum = 0;
  while(N != 0) {
    sum += ((N%10) * (N%10));
    N /= 10;
  }
  return sum;
}
