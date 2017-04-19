#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
    vector<vector<int> > arr(N, vector<int>(3));
    for(int i = 0; i < N; i++) 
      cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    
    for(int i = 1; i < N; i++) {
      arr[i][0] += std::min(arr[i-1][1], arr[i-1][2]);
      arr[i][1] += std::min(arr[i-1][0], arr[i-1][2]);
      arr[i][2] += std::min(arr[i-1][1], arr[i-1][0]);
    }
    cout << std::min(std::min(arr[N-1][0], arr[N-1][1]), arr[N-1][2])
      << endl;
  }
  return 0;
}
