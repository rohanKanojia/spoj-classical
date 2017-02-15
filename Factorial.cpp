#include <iostream>
using namespace std;

long long getTrailingZeroes(long long a) {
  long long num = 5, ans = 0;
  while(num <= a) {
    ans += (a/num);
    num *= 5;
  }
  return ans;
}

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long a;
    cin >> a;
    cout << getTrailingZeroes(a) << endl;
  }
  return 0;
}
