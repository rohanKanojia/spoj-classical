#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool criteria(vector<long long>& boxes, long long K, long long mid) {
  for(long long i = boxes.size()-1; i >= 0; i--) {
    K -= (boxes[i]/mid);
    if(K <= 0)
      return true;
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    long long N, K;
    scanf("%lld%lld", &N, &K);
    
    vector<long long> boxes(N);
    for(long long i = 0; i < N; i++)
      scanf("%lld", &boxes[i]);

    std::sort(boxes.begin(), boxes.end());
    int start = 1, end = boxes[N-1]+1;
    while(start < end) {
      long long mid = (start + end)>>1;
      if(criteria(boxes, K, mid))
        start = mid+1;
      else
        end = mid;
    }
    printf("%lld\n", start-1);
  }
  return 0;
}
