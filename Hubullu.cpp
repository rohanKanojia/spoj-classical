#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N, player;
    cin >> N >> player;

    if(player == 1) {
      cout << "Pagfloyd wins.\n";
    }
    else {
      cout << "Airborne wins.\n";
    }
  }
  return 0;
}
