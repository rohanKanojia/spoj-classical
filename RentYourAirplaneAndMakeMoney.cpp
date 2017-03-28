#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Order { long long start, end, cost; } Order;
bool myComp(Order a, Order b) { return a.end < b.end; }
long long getMaxProfit(vector<Order>& arr, long long N);
long long getPrevOrder(vector<Order>& arr, long long i);
bool compVal(Order a, Order target) { return a.end <= target.start; }

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);
    
    vector<Order> arr(N);
    for(long long i = 0; i < N; i++) { 
      scanf("%lld%lld%lld", &arr[i].start, &arr[i].end, &arr[i].cost);
      arr[i].end += arr[i].start;
    }

    long long ans = getMaxProfit(arr, N);
    printf("%lld\n", ans);
  }
  return 0;
}

long long getMaxProfit(vector<Order>& arr, long long N) {
  vector<long long> dp(N);
  std::sort(arr.begin(), arr.end(), myComp);

  dp[0] = arr[0].cost;
  for(long long i = 1; i < N; i++) {
    long long curCost = arr[i].cost;
    long long j = getPrevOrder(arr, i);

    if(j != -1)
      curCost += dp[j];

    dp[i] = std::max(curCost, dp[i-1]);
  }

  return dp[N-1];
}

long long getPrevOrder(vector<Order>& arr, long long i) {
  long long start = 0, end = i-1;
  while(start <= end) {
    long long mid = (start+end)>>1;
    if(arr[mid].end <= arr[i].start) {
      if(arr[mid+1].end <= arr[i].start)
        start = mid+1;
      else
        return mid;
    }
    else
      end = mid-1;
  }
  return -1;
}
