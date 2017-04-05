#include <iostream>
#include <string>
using namespace std;

int main() {
  string ss;
  int nCase = 1;
  while(cin >> ss) {
    int nSteps = 0;

    for(int i = 0; i < ss.length(); i++) {
      if((ss[i] == '1' && nSteps%2 == 0) || (ss[i] == '0' && nSteps%2 == 1))
        nSteps++;
    }
    cout << "Game #"<<nCase++ << ": "<<nSteps << endl;
  }
  return 0;
}
