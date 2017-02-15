#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N = 1;
  while(N != -1) {
    cin >> N;
    if(N == -1) break;

    vector<long long> arr;
    long long ans = 0, avg = 0, sum = 0;
    for(long long i = 0; i < N; i++) {
      long long tmp;
      cin >> tmp;
      arr.push_back(tmp);
      sum += tmp;
    }

    avg = sum / arr.size();

    if(avg * arr.size() == sum) {
      for(long long i = 0; i < N; i++) {
        if(arr[i] > avg) {
          ans += arr[i]-avg;
        }
      }
      cout << ans << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
  return 0;
}
