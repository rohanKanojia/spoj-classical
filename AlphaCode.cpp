#include <iostream>
#include <map>
#include <string>
using namespace std;

long long getDigit(char aChar) {
  return aChar - '0';
}

long long isValidCharacter(long long num) {
  return num >= 1 && num <= 26;
}

long long getPossibleDecodings(string& ss, long long curIndex, std::map<long long, long long>& waysMap) {
  if(curIndex > ss.length() || ss[curIndex] == '0')
    return 0;
  if(curIndex == ss.length())
    return 1;
  if(waysMap.find(curIndex) == waysMap.end()) {
    long long nWays = 0;
    if(isValidCharacter(getDigit(ss[curIndex]))) {
      nWays += getPossibleDecodings(ss, curIndex+1, waysMap);
    }
    if(isValidCharacter(getDigit(ss[curIndex])*10 + getDigit(ss[curIndex+1]))) {
      nWays += getPossibleDecodings(ss, curIndex+2, waysMap);
    }
    waysMap[curIndex] = nWays;
  }
  return waysMap[curIndex];
}

int main() {
  string ss;
  while(1) {
    cin >> ss;
    map<long long, long long> waysMap;
    if(ss == string("0"))
      break;

    cout << getPossibleDecodings(ss, 0, waysMap) << endl;
  }
  return 0;
}
