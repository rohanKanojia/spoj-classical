#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  double N = 1;

  while(1) {
    cin >> N;
    if(N == 0) break;
  
    double ans = (N * N)/(2 * M_PI);

    cout << std::fixed << std::setprecision(2) << ans << endl;
  }

  return 0;
}
