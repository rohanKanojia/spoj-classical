#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long long T, nCase = 1;
  cin >> T;

  while(T--) {
    long long N;
    cin >> N;
    vector<long long> arr(N);
    for(long long i = 0; i < N; i++)
      cin >> arr[i];


    long long sum = 0, ans = 0;
    for(long long i = 0; i < N; i++) {
      if(sum + arr[i] < 0) {
        long long curVal = abs(arr[i] + sum)+1;
        ans = std::max(curVal, ans);
      }
      sum += arr[i];
    }
    if(ans == 0)
      ans = 1;

    cout << "Scenario #"<< nCase++ << ": " << ans << endl;
  }
  return 0;
}
