#include <cstdio>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class MaxQueue {
  queue<long long> qq;
  long long maxElem;
public:
  MaxQueue() : maxElem(INT_MIN) { }
  void push(long long item) {
    maxElem = std::max(item, maxElem);
    qq.push(item);
  }
  void pop() {
    if(qq.front() == maxElem) {
      queue<long long> tmpQueue = qq;;
      tmpQueue.pop();
      maxElem = INT_MIN;
      while(!tmpQueue.empty()) {
        maxElem = std::max(tmpQueue.front(), maxElem);
        tmpQueue.pop();
      }
    }
    qq.pop();
  }
  long long getMax() { return maxElem; }
};

int main() {
  long long N, K;
  scanf("%lld", &N);
  vector<long long> arr(N);
  MaxQueue mq;

  for(long long i = 0; i < N; i++) {
    scanf("%lld", &arr[i]);
  }
  scanf("%lld", &K);

  long long i;
  for(i = 0; i < K; i++)
    mq.push(arr[i]);
  
  while(i < N) {
    printf("%lld ", mq.getMax());
    mq.pop();
    mq.push(arr[i++]);
  }
  printf("%lld\n", mq.getMax());
  return 0;
}
