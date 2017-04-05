#include <string>
#include <iostream>
using namespace std;

int main() {
  string ss;
  while(cin >> ss) {
    int firstUp = 0, firstLow = 0;
    for(int i = 0; i < ss.length(); i++) {
      if(i%2 == 0 && islower(ss[i])) firstLow++;
      if(i%2 == 1 && isupper(ss[i])) firstLow++;

      if(i%2 == 0 && isupper(ss[i])) firstUp++;
      if(i%2 == 1 && islower(ss[i])) firstUp++;
    }
    cout << std::min(firstUp, firstLow) << endl;
  }
  return 0;
}
