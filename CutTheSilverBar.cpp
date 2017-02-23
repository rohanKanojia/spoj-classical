#include <iostream>
#include <cmath>
using namespace std;

int main() {
  while(1) {
    long long N;
    cin >> N;
    if(N == 0) break;

    long long ans = 0;
    while(N > 1) {
      N >>= 1;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
