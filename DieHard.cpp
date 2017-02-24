#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long H, A;
    cin >> H >> A;

    long long nTime = 1;
    H += 3, A += 2;
    while(1) {
      if(H > 5 && A > 10) { // water
        H -= 2;
        A -= 8;
        nTime += 2;
      }
      else if(H > 20) { // fire
        H -= 17;
        A += 7;
        nTime += 2;
      }
      else
        break;
    }

    cout << nTime << endl;
  }
  return 0;
}
