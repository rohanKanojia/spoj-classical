#include <iostream>
using namespace std;

int main() {
  long long N = 1;

  while(1) {
    cin >> N;
    if(N == 0) 
      break;

    // For calculating squares you just need to think bottom down:
    // N^2 + (N-1)^2 + (N-2)^2 + .. + 1^2
    long long sum = (N * (N+1) * (2*N+1))/6;
    cout << sum << endl;
  }

}
