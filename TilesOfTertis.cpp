#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  while(true) {
    long long N, K;
    cin >> N >> K;
    if(N == 0 || K == 0)
      break;

    long long div = std::__gcd(N, K);
    long long ans = (N/div) * (K/div);
    cout << ans << endl;
  }
  return 0;
}
