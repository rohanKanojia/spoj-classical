#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  long long T;
  cin >> T;
  while(T--) {
    string ss;
    long long ans = 1;
    cin >> ss;
    
    if(ss.find(".") != string::npos) {
      long long pivot = ss.find(".");
      string firstHalf = ss.substr(0, pivot);
      string secondHalf = ss.substr(pivot+1, ss.length()-pivot);
      
      long long numerator = stoi(firstHalf + secondHalf);
      long long denominator = pow(10, secondHalf.length());

      ans = denominator/std::__gcd(numerator, denominator);
    }
    cout << ans << endl;
  }
  return 0;
}
