#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

long long getDigitVal(long long x) {
  long long res = 1;
  for(long long i = 0; i < x; i++) 
    res = (i == 1 ? res * 18 : res * 20);
  return res;
}

int main() {
  map<string, int> mapDigits;
  mapDigits[string("S")]           = 0;
  mapDigits[string(".")]           = 1;
  mapDigits[string("..")]          = 2;
  mapDigits[string("...")]         = 3;
  mapDigits[string("....")]        = 4;
  mapDigits[string("-")]           = 5;
  mapDigits[string(". -")]         = 6;
  mapDigits[string(".. -")]        = 7;
  mapDigits[string("... -")]       = 8;
  mapDigits[string(".... -")]      = 9;
  mapDigits[string("- -")]         = 10;
  mapDigits[string(". - -")]       = 11;
  mapDigits[string(".. - -")]      = 12;
  mapDigits[string("... - -")]     = 13;
  mapDigits[string(".... - -")]    = 14;
  mapDigits[string("- - -")]       = 15;
  mapDigits[string(". - - -")]     = 16;
  mapDigits[string(".. - - -")]    = 17;
  mapDigits[string("... - - -")]   = 18;
  mapDigits[string(".... - - -")]  = 19;
  while(true) {
    long long N;
    cin >> N;
    if(N == 0) break;
    
    getchar();
    vector<string> digits;
    string curDigit;
    for(long long i = 0; i < N; i++) {
      getline(cin, curDigit);
      digits.push_back(curDigit);
    }

    reverse(digits.begin(), digits.end());
    long long ans = 0;
    for(long long i = 0; i < digits.size(); i++) 
      ans += getDigitVal(i) * mapDigits[digits[i]]; 

    cout << ans << endl;
  }
  return 0;
}
