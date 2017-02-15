#include <iostream>
using namespace std;

int main() {
  double N;
  while(1) {
    cin >> N;
    if(N == 0.00)
      break;
    double res = 0;
    long long i = 1;
    while(res < N) {
      i++;
      res = res + (1./i);
    }
    cout << i-1 << " card(s)" <<  endl;
  }
  return 0;
}
