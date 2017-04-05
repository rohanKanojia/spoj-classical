#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  long long a[4], nCase = 1;
  while(cin >> a[0] >> a[1] >> a[2] >> a[3]) {
    std::sort(a, a+4);
    cout << "Case "<< nCase++ << ": " << a[2]+a[3] << endl;
  }
  return 0;
}
