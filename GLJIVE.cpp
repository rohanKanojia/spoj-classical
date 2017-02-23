#include <iostream>
#include <vector>
using namespace std;

int main() {
  const long long N = 10;
  vector<long long> arr(N);
  for(long long i = 0; i < N; i++)
    cin >> arr[i];

  long long sum = 0;
  for(long long i = 0; i < N; i++) {
    sum += arr[i];
    if(sum >= 100) {
      if(100-(sum-arr[i]) < sum-100)
        sum -= arr[i];
      break;
    }
  }
  cout << sum << endl;
  return 0;
}
