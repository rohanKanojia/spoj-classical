#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long T;
  cin >> T;
   
  while(T--) {
    long long N, K, M;
    cin >> N >> K >> M;
    
    long long t = 0, atoms = N*K;
    if(K <= M/N) {
      t++;
      while(K <= M/atoms) {
        t++;
        atoms *= K;
      }
    }
    cout << t << endl;
  }
  return 0;
}
