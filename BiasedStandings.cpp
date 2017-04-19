#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N;
    string names;
    cin >> N;
    vector<long long> arr(N);
    for(long long i = 0; i < N; i++)
      cin >> names >> arr[i];
    std::sort(arr.begin(), arr.end());

    long long sum = 0;
    for(long long i = 0; i < N; i++) 
      sum += abs(arr[i]-(i+1));
    cout << sum << endl;
  }
  return 0;
}
