#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long a, b;
    cin >> a >> b;

    long long ans = floor(abs(a-b)/std::__gcd(abs(a), abs(b)));
    cout << ans << endl;
  }
  return 0;
}
