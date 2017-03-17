#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
using namespace std;

int main() {
  int T;
  string aLine, aWord;
  cin >> T;
  getline(cin, aLine);

  while(T--) {
    getline(cin, aLine);
    istringstream sin(aLine);
    int ans = 0, prevSize = 0, count = 0;

    while(sin >> aWord) {
      if(aWord.length() == prevSize)
        count++;
      else {
        prevSize = aWord.length();
        count = 1;
      }
      ans = std::max(count, ans);
    }
    

    cout << ans << endl;
  }
  return 0;
}
