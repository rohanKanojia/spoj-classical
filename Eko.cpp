#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long binarySearch(vector<long long>& arr, long long start, long long end, long long M) {
  long long ans = -1;
  while(start <= end) {
    long long mid = (start+end)>>1;

    long long sum = 0;
    for(long long i = 0; i < arr.size(); i++)
      sum += std::max(arr[i] - mid, (long long)0);
    
    if(sum == M)
      return mid;
    else if(sum > M) {
      start = mid+1;
      ans = std::max(ans, mid);
    }
    else
      end = mid-1;
  }
  return ans;
}

int main() {
  long long N, M, maxVal = -1;
  scanf("%lld%lld", &N, &M);
  vector<long long> arr;
  arr.push_back(0);
  for(int i = 0; i < N; i++) {
    long long tmp;
    scanf("%lld", &tmp);
    maxVal = std::max(maxVal, tmp);
    arr.push_back(tmp);
  }


  printf("%lld\n", binarySearch(arr, 0, maxVal, M));
  return 0;
}
