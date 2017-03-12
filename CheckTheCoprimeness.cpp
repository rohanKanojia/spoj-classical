#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N, ans;
    cin >> N;

    if(N%2 == 0) {
      ans = N/2 - 1;
      if(ans%2 == 0)
        cout << ans-1 << endl;
      else
        cout << ans << endl;
    }
    else
      cout << N/2 << endl;  
  }
  return 0;
}
