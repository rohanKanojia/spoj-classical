#include <iostream>
using namespace std;

long long reverseOf(long long x) {
  long long rev = 0;
  while(x) {
    rev = (rev*10) + (x%10);
    x /= 10;
  }
  return rev;
}

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long a, b;
    cin >> a >> b;
    cout << reverseOf(reverseOf(a) + reverseOf(b)) << endl;
  }
}
