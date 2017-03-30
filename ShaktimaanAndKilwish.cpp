#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N;
    cin >> N;

    cout << (N%2 == 0 ? "Thankyou Shaktiman" : "Sorry Shaktiman") << endl;
  }
  return 0;
}
