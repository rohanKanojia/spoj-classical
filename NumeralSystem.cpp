#include <iostream>
#include <map>
#include <string>
using namespace std;

long long convert(string& a, map<char, int>& getDecimal);
string revert(int a, map<int, char>& getChar);

int main() {
  long long T;
  cin >> T;

  while(T--) {
    string a, b;
    cin >> a >> b;

    map<char, int> getDecimal;
    getDecimal['m'] = 1000;
    getDecimal['c'] = 100;
    getDecimal['x'] = 10;
    getDecimal['i'] = 1;

    map<int, char> getChar;
    getChar[1000] = 'm';
    getChar[100]  = 'c';
    getChar[10]   = 'x';
    getChar[1]    = 'i';
    int res = convert(a, getDecimal) + convert(b, getDecimal);
    cout << revert(res, getChar) << endl;
  }
  return 0;
}

long long convert(string& a, map<char, int>& getDecimal) {
  int i = a.length()-1, res = 0;
  while(i >= 0) {
    if(isalpha(a[i])) {
      if(i-1 >= 0 && isdigit(a[i-1])) {
        res += getDecimal[a[i]] * (a[i-1] - '0');
        i -= 2;
      }
      else {
        res += getDecimal[a[i]];
        i--;
      }
    }
  }
  return res;
}

string revert(int a, map<int, char>& getChar) {
  string res("");
  for(int i = 1000; i > 0 && a > 0; i /= 10) {
    int q = a / i;
    if(q == 1) {
      res += getChar[i];
      a %= i;
    }
    else if(q > 0) {
      char curDigit = '0' + q;
      res += curDigit;
      res += getChar[i];
      a %= i;
    }
  }
  return res;
}
