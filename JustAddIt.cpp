#include <iostream>
using namespace std;

long long modExp(long long a, long long b, long long N) {
  long long res = 1;

  while(b) {
    if(b&1) {
      res = (res * a) % N;
    }
    b >>= 1;

    a = (a * a) % N;
  }
  return res;
}

int main() {
  while(true) {
    long long N, K;
    cin >> N >> K;
    if(N == 0 && K == 0)
      break;

    long long ans = modExp(N, K, 10000007) +
                    2*modExp(N-1, K, 10000007) +
                    modExp(N, N, 10000007) +
                    2*modExp(N-1, N-1, 10000007);
    cout << ans % 10000007 << endl;
  }
  return 0;
}
