#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N, K, ans = 0;
    cin >> N >> K;

    if(K > 2) {
      K--;
      while(K > 1) {
        if(K%2 != 0)
          ans++;
        K >>= 1;
      }
    }
    else
      ans = K;
    cout << (ans%2 == 0 ? "Female" : "Male") << endl;
  }
  return 0;
}
