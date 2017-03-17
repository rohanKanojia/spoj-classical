#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> T(31, 0), F(31, 0);
  int n;

  T[0] = 1;
  F[0] = 0;
  for(int i = 1; i < 31; i++) {
    F[i] += T[i-1];
    if(i >= 2) {
      T[i] += 3*T[i-2];
      F[i] += F[i-2];
    }
    if(i >= 3)
      T[i] += 2*F[i-3];
  }

  while(true) {
    cin >> n;
    if(n == -1) break;

    cout << T[n] << endl;
  }
}
