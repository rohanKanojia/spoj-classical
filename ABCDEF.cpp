#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long N, ans;
  scanf("%lld", &N);
  vector<long long> arr(N), lhs, rhs;
  for(long long i = 0; i < N; i++)
    scanf("%lld", &arr[i]);

  for(long long a = 0; a < arr.size(); a++) {
    for(long long b = 0; b < arr.size(); b++) {
      for(long long c = 0; c < arr.size(); c++) {
        lhs.push_back(arr[a]*arr[b] + arr[c]);
      }
    }
  }
  for(long long d = 0; d < arr.size(); d++) {
    for(long long e = 0; e < arr.size(); e++) {
      for(long long f = 0; f < arr.size(); f++) {
        if(arr[d] == 0) continue;
        rhs.push_back(arr[f]*arr[d] + arr[e]*arr[d]);
      }
    }
  }

  sort(lhs.begin(), lhs.end());
  sort(rhs.begin(), rhs.end());

  ans = 0;
  for(long long i = 0; i < lhs.size(); i++) {
    long long firstPos, lastPos;
    firstPos = lower_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
    lastPos  = upper_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();

    ans += (lastPos - firstPos);
  }

  printf("%lld\n", ans);
  return 0;
}
