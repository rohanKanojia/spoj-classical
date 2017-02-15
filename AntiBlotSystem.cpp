#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
  long long T;
  cin >> T;
  while(T--) {
    string input;
    if(T == 2) getchar();
    while(input.length() <= 1) {
      getline(cin, input);
    }
    long long a, b, c;
    string aStr, bStr, cStr;

    aStr = input.substr(0, input.find('+'));
    bStr = input.substr(input.find('+')+1, input.find('=')-input.find('+')-1);
    cStr = input.substr(input.find('=')+1, input.length() - input.find('='));
    if(aStr.find("machula") != string::npos) {
      b = std::stoi(bStr);
      c = std::stoi(cStr);
      a = c - b;
    }
    else if(bStr.find("machula") != string::npos) {
      a = std::stoi(aStr);
      c = std::stoi(cStr);
      b = c - a;
    }
    else {
      a = std::stoi(aStr);
      b = std::stoi(bStr);
      c = a + b;
    }
    cout << a << " + " << b << " = " << c << endl;
  }
  return 0;
}
