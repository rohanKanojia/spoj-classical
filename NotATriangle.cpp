#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  while(true) {
    long long N;
    cin >> N;
    if(N == 0) break;
    vector<long long> arr(N);
    for(long long i = 0; i < N; i++)
      cin >> arr[i];

    std::sort(arr.begin(), arr.end());
    long long ans = 0;

    for(long long first = arr.size()-1; first >= 2; first--) {
      long long second = 0, third = first-1;
      while(second < third) {
        if(arr[second] + arr[third] < arr[first]) {
          ans += third - second;
          second++;
        }
        else
          third--;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
