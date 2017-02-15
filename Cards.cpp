#include <iostream>
using namespace std;

const long long modVal = 1000007;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N;
    cin >> N;

    long long ans = (N*N + ((N * (N+1)/2))) % modVal;

    cout << ans << endl;
  }
  return 0;
}
