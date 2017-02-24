#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  string ss;
  while(true) {
    cin >> ss;
    if(ss == string("00e0"))
      break;

    long long N = (ss[0]-'0')*10 + (ss[1]-'0');
    N *= pow(10, ss[3]-'0');
    long long nearestPower2 = log2(N);
    nearestPower2 = 1<<nearestPower2;
    long long ans = 1 + (N-nearestPower2)*2;
    cout << ans << endl;
  }
  return 0;
}
