#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N;
    cin >> N;
    vector<long long> arr(N);
    for(long long i = 0; i < N; i++)
      cin >> arr[i];

    long long ans = 0;
    // Each element added i times and subtracted (N-1-i) times
    for(long long i = 0; i < N; i++)
      ans += (i*arr[i] - arr[i]*(N-1-i));
    cout << ans << endl;
  }
  return 0;
}
