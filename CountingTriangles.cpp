#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N;
    cin >> N;

    long long ans = (N * (N+2) * (2*N+1))/8;

    cout << ans << endl;
  }
  
  return 0;
}
