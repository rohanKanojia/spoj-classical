#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long T;
  scanf("%lld", &T);
  while(T--) {
    long long N;
    scanf("%lld", &N);
    vector<long long> arr(N);
    for(long long i = 0; i < N; i++)
      scanf("%lld", &arr[i]);
    sort(arr.begin(), arr.end());

    bool bTransmitted = false;
    long long count, ans;
    for(long long i = 0; i < N; ) {
      count = 0;
      do {
        count++;
        i++;
      } while(i < N && arr[i] == arr[i-1]);
      
      if(count > N/2) {
        bTransmitted = true;
        ans = arr[i-1];
        break;
      }
    }

    if(bTransmitted)
      printf("YES %lld\n", ans);
    else
      printf("NO\n");
  }
}
