#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long N, ans;
    cin >> N;

    if(N%2 == 0) {
      ans = 5*(N/2) - 1;
      ans = ans*100 + 42;
    }
    else {
      ans = 5*(N/2) + 1;
      ans = ans*100 + 92;
    }
    cout << ans << endl;
  }
  return 0;
}
