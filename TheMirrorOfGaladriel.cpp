#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  long long T;
  cin >> T;
  
  while(T--) {
    string a, revA;
    cin >> a;
    revA = a;
    std::reverse(revA.begin(), revA.end());
    if(a == revA)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
