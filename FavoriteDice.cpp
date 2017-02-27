#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  long long T;
  cin >> T;
  while(T--) {
    double N, harmonicSum = 0.0;
    cin >> N;

    for(long long i = 1; i <= N; i++) {
      harmonicSum += 1.0f/i;
    }
    double ans = N * harmonicSum;
    cout << std::fixed << std::setprecision(2) << ans << endl;
  }
  return 0;
}
