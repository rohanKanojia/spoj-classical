#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N, M;
    cin >> N >> M;
    N--, M--;

    vector<long long> x(N), y(M);
    for(long long i = 0; i < N; i++)
      cin >> x[i];
    for(long long i = 0; i < M; i++)
      cin >> y[i];

    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());

    long long nH = 1, nV = 1, i = 0, j = 0, ans = 0;
    while(i < N && j < M) {
      if(x[i] > y[j]) {
        ans += x[i]*nV;
        nH++;
        i++;
      }
      else {
        ans += y[j]*nH;
        nV++;
        j++;
      }
    }
    if(i < N) {
      long long sum = 0;
      while(i < N)
        sum += x[i++];
      ans += sum*nV;
    }
    else {
      long long sum = 0;
      while(j < M)
        sum += y[j++];
      ans += sum*nH;
    }
    cout << ans << endl;
  }
  return 0;
}
