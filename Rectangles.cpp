#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long N, ans, sqrtN;
  cin >> N;

  sqrtN = sqrt(N);
  ans = sqrtN; // number of square rectangles :

  for(long long i = 1; i <= sqrtN; i++) {
    for(long long j = i+1; j*i <= N; j++) {
      ans++;
    }
  }

  cout << ans;
  return 0;
}

