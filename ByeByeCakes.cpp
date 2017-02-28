#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long items[4], required[4];
  while(true) {
    cin >> items[0] >> items[1] >> items[2] >> items[3];
    cin >> required[0] >> required[1] >> required[2] >> required[3];

    if(items[0] == -1 && items[1] == -1 && items[2] == -1 && items[3] == -1)
      break;

    long long maxCakes = 0;
    for(long long i = 0; i < 4; i++) {
      if(required[i] != 0) {
        long long curCakes = ceil((double)items[i]/required[i]);
        maxCakes = std::max(curCakes, maxCakes);
      }
    }

    for(long long i = 0; i < 4; i++)
      cout << maxCakes*required[i] - items[i] << " ";
    cout << endl;
  }
  return 0;
}
