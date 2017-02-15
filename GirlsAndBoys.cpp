#include <iostream>
#include <cmath>
using namespace std;

int main() {
  while(1) {
    long long G, B;
    cin >> G >> B;
    if(G == -1 && B == -1)
      break;

    long long ans;
    if(G > B) {
      ans = ceil((double)G/(B+1));
    }
    else {
      ans = ceil((double)B/(G+1));
    }
    cout << ans << endl;
  }
  return 0;
}
