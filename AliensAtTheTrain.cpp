#include <cstdio>
#include <vector>
using namespace std;

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N, K;
    scanf("%lld%lld", &N, &K);

    vector<long long> arr(N);
    for(long long i = 0; i < N; i++)
      scanf("%lld" , &arr[i]);

    long long maxPeople = 0, curSum = 0, curElem = 0, start = 0, nTrains = 0;
    for(long long i = 0; i < N; i++) {
      curSum += arr[i];
      curElem++;
      while(curSum > K && start >= 0) {
        curSum -= arr[start];
        start++;
        curElem--;
      }
      if((nTrains < curElem) || (nTrains == curElem && maxPeople > curSum)) { // minimize people and maximize stations
        maxPeople = curSum;
        nTrains = curElem;
      }
    }
    printf("%lld %lld\n", maxPeople, nTrains);
  }
  return 0;
}
