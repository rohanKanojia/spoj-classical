#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

int main() {
  long long N, K;
  vector<long long> hotels;
  scanf("%lld%lld", &N, &K);

  for(long long i = 0; i < N; i++) {
    long long tmp;
    scanf("%lld", &tmp);
    hotels.push_back(tmp);
  }

  long long curSum = hotels[0], start = 0, ans = INT_MIN;
  for(long long i = 1; i <= N; i++) {
    while(curSum > K && start <= i-1) {
      // remove the front element
      curSum -= hotels[start];
      start++;
    }
    ans = std::max(ans, curSum);
    curSum += hotels[i];
  }
  printf("%lld\n", ans);
  return 0;
}

