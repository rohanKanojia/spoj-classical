#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--) {
    double a, b, c;
    cin >> a >> b >> c;
    double s = (a+b+c)/2.0;
    double ans = (((a*a+b*b+c*c) * (sqrt(3.0)))/4.0 + 3*sqrt(s*(s-a)*(s-b)*(s-c)))/2.0;
    cout << std::fixed << std::setprecision(2) << ans << endl;
  }
  return 0;
}
