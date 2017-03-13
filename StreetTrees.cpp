#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long> arr(N);
  for(long long i = 0; i < N; i++)
    cin >> arr[i];

  std::sort(arr.begin(), arr.end());

  long long ans = 0, minDivisor = arr[1] - arr[0];
  for(long long i = 1; i < N-1; i++)
    minDivisor = std::__gcd(minDivisor, arr[i+1]-arr[i]);

  for(long long i = 1; i < N; i++)
    ans += ((arr[i] - arr[i-1])/minDivisor - 1);
  cout << ans << endl;
  return 0;
}
