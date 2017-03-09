#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string negativeBase(long long N, long long baseVal) {
  string result;

  while(N) {
    long long r = N % baseVal;
    N /= baseVal;

    if(r < 0) {
      r += -1*baseVal;
      N++;
    }
    result += (char)('0' + r);
  }
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  long long N;
  cin >> N;

  if(N == 0)
    cout << 0 << endl;
  else
    cout << negativeBase(N, -2) << endl;
  return 0;
}
