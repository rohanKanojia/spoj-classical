#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
  long long N, nCase = 1;
  while(true) {
    cin >> N;
    if(N == 0) break;

    vector<vector<long long> > arr(N, vector<long long>(3));
    for(long long i = 0; i < N; i++) {
      for(long long j = 0; j < 3; j++)
        cin >> arr[i][j];
    }

    arr[0][2] += arr[0][1];
    for(long long i = 1; i < N; i++) {
      if(i == 1) {
        arr[i][0] += arr[i-1][1];
        arr[i][1] += min(arr[i][0], min(arr[i-1][1], arr[i-1][2]));
        arr[i][2] += min(arr[i][1], min(arr[i-1][1], arr[i-1][2]));      
      }
      else {
        arr[i][0] += min(arr[i-1][0], arr[i-1][1]);
        arr[i][1] += min(min(min(arr[i-1][0], arr[i-1][1]), arr[i-1][2]), arr[i][0]);
        arr[i][2] += min(arr[i][1], min(arr[i-1][1], arr[i-1][2]));
      }
    }

    cout << nCase++ << ". " << arr[N-1][1] << endl;
  }
  return 0;
}
