#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long T, J = 1;
  cin >> T;
  while(J <= T) {
    long long K, N, i;
    cin >> K >> N;
    vector<long long> arr;
    for(i = 0; i < N; i++) {
      long long tmp;
      cin >> tmp;
      arr.push_back(tmp);
    }
    std::sort(arr.begin(), arr.end());

    long long nStamps = 0;
    cout << "Scenario #" << J++ << ":\n";
    for(i = N-1; i >= 0; i--) {
      nStamps += arr[i];
      if(nStamps >= K)
        break;
    }

    if(nStamps < K)
      cout << "impossible" << endl; 
    else
      cout << N-i << endl;
  }
}
