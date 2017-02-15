#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  long long T, nCase = 1;
  cin >> T;

  while(T--) {
    long long r;
    double ans, x;
    cin >> r;

    x = sqrt(16 * r * r - 1) / 2;
    ans = x * x + sqrt(4 * r * r - x * x);

    cout << "Case "<< nCase++ << ": ";
    cout << std::fixed << std::setprecision(2) << ans << endl;

  }
  return 0;
}
