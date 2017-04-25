#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

long long toDecimal(string ss, int base) {
  long long res = 0, powBase = 1;
  for(int i = ss.length()-1; i >= 0; i--, powBase *= base) {
    if(ss[i] > 47 && ss[i] < 58) 
      res += powBase * (ss[i] - '0');
    else 
      res += powBase * (ss[i] - ('A' - 10));
  }
  return res;
}

string fromDecimal(long long num, int base) {
  string ss;
  for(; num != 0; num /= base) {
    int curDigit = num % base;
    if(curDigit < 10)
      ss += ('0' + curDigit);
    else
      ss += ('A'-10 + curDigit);
  }
  if(ss == "") return "0";
  std::reverse(ss.begin(), ss.end());
  return ss;
}

int main() {
  string ss, decimalVal, resVal;
  int fromBase, toBase;
  
  while(cin >> ss >> fromBase >> toBase) {
    long long tempDecimal = toDecimal(ss, fromBase);
    resVal = fromDecimal(tempDecimal, toBase);
    if(resVal.length() > 7)
      cout << "  ERROR\n";
    else
      cout << setw(7) << resVal << endl;
  }
  return 0;
}
