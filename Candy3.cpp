#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long N, sum = 0;
    cin >> N;

    for(long long i = 0; i < N; i++) {
      long long tmp;
      cin >> tmp;
      sum = (sum+tmp) % N;
    }

    if(sum%N == 0) {
      cout << "YES\n";
    }
    else
      cout << "NO\n";
  }
  return 0;
}
