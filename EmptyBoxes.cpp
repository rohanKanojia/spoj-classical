#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N, K, F, T;
    cin >> N >> K >> T >> F;

    long long ans = N + K*((F-N)/(K-1));
    cout << ans << endl;
  }
  return 0;
}
