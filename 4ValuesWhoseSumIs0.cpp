#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long> a(N), b(N), c(N), d(N);

  for(long long i = 0; i < N; i++) 
    cin >> a[i] >> b[i] >> c[i] >> d[i];

  vector<long long> lhs;
  vector<long long> rhs;
  for(long long i = 0; i < N; i++) {
    for(long long j = 0; j < N; j++) {
      lhs.push_back(a[i]+b[j]);
    }
  }

  for(long long i = 0; i < N; i++) {
    for(long long j = 0; j < N; j++) {
      rhs.push_back(c[i]+d[j]);
    }
  }

  sort(lhs.begin(), lhs.end());
  sort(rhs.begin(), rhs.end());

  long long ans = 0;
  for(long long i = 0; i < lhs.size(); i++) {
    long long firstPos, lastPos;
    firstPos = lower_bound(rhs.begin(), rhs.end(), lhs[i]*-1)-rhs.begin();
    lastPos = upper_bound(rhs.begin(), rhs.end(), lhs[i]*-1)-rhs.begin();
    
    ans += (lastPos-firstPos); 
  }
  cout << ans << endl;
  return 0;
}
