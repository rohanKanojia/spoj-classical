#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long lcm(long long a, long long b) { return a*b/std::__gcd(a, b); }

int main() {
  while(true) {
    string ss;
    cin >> ss;
    if(ss[0] == '*') break;
    
    long long minVal = 1;
    for(long long i = 0; i < ss.length(); i++) {
      if(ss[i] == 'Y') {
        minVal = lcm(i+1, minVal);
      }
    }
    for(long long i = 0; i < ss.length(); i++) {
      if(ss[i] == 'N' && minVal % (i+1) == 0) {
        minVal = -1;
        break;
      }
    }
    cout << minVal << endl;
  }
  return 0;
}
