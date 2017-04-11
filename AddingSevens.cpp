#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int codeToDecimal(string codeStr, map<string, int>& displayCode) {
  int res = 0;
  for(int i = 0; i < codeStr.length(); i += 3) 
    res = 10*res + displayCode[codeStr.substr(i, 3)];
  return res;
}

string decimalToCode(int N, map<int, string>& codeDisplay) {
  string res;
  while(N > 0) {
    res = codeDisplay[N%10] + res;
    N /= 10;
  }
  return res;
}

int main() {
  map<string, int> displayCode = {
    {"063", 0}, {"010", 1}, {"093", 2}, {"079", 3}, {"106", 4},
    {"103", 5}, {"119", 6}, {"011", 7}, {"127", 8}, {"107", 9}
  };
  map<int, string> codeDisplay = {
    {0, "063"}, {1, "010"}, {2, "093"}, {3, "079"}, {4, "106"},
    {5, "103"}, {6, "119"}, {7, "011"}, {8, "127"}, {9, "107"}
  };
  while(true) {
    string line;
    cin >> line;
    if(line == "BYE") break;

    int midPos = line.find("+");
    string a = line.substr(0, midPos);
    string b = line.substr(midPos+1, line.length()-2-midPos);

    int ans = codeToDecimal(a, displayCode) + codeToDecimal(b, displayCode);
    cout << line << decimalToCode(ans, codeDisplay) << endl;
  }
  return 0;
}
