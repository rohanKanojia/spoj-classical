#include <iostream>
using namespace std;

long long C(int N, int R) {
  if(R > N/2)
    R = N-R;

  long long res = 1;
  for(long long i = 1; i <= R; i++) {
    res = res * N;
    res = res / i;
    N--;
  }
  return res;
}

int main() {
  long long T;
  cin >> T;
  
  while(T--) {
    long long N, K, r;
    cin >> N >> K;

    // Since we need at least one marble from each color.
    // K marbles are already selected of 1, 2, 3..K.
    r = N-K;

    cout << C(K+r-1, r) << endl;
  }
  return 0;
}
