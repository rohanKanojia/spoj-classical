#include <iostream>
#include <climits>
using namespace std;

int main() {
  long long nA, nD;
  while(1) {
    cin >> nA >> nD;
    if(nA == 0 && nD == 0) break;

    long long defender1 = INT_MAX, defender2= INT_MAX, attacker1 = INT_MAX;

    for(long long i = 0; i < nA; i++) {
      long long tmp;
      cin >> tmp;
      if(tmp < attacker1) {
        attacker1 = tmp;
      }
    }

    for(long long i = 0; i < nD; i++) {
      long long tmp;
      cin >> tmp;
      if(tmp <= defender1) {
        defender2 = defender1;
        defender1 = tmp;
      }
      if(tmp > defender1 && tmp < defender2) {
        defender2 = tmp;
      }
    }


    if(attacker1 < defender2) {
      cout << "Y\n";
    }
    else
      cout << "N\n";
  }
  return 0;
}
