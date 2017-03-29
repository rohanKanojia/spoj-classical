#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int T, nCase = 1;
  cin >> T;

  while(T--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << "Case " << nCase++ << ": "
      << (c%(std::__gcd(a, b)) == 0 ? "Yes" : "No") << endl;
  }
  return 0;
}
