#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
  long long M, N;
  cin >> M >> N;

  vector<vector<long long> > arr(M, vector<long long>(N));

  for(long long i = 0; i < M; i++)
    for(long long j = 0; j < N; j++)
      cin >> arr[i][j];

  for(long long i = 1; i < M; i++) {
    for(long long j = 0; j < N; j++) {
      long long minVal = INT_MAX;
      if(j-1 > 0)
        minVal = std::min(minVal, arr[i-1][j-1]);
      if(j+1 < N)
        minVal = std::min(minVal, arr[i-1][j+1]);
      
      arr[i][j] += std::min(minVal, arr[i-1][j]);
    }
  }


  long long ans = arr[M-1][0];
  for(long long i = 0; i < N; i++)
    ans = std::min(arr[M-1][i], ans);
  cout << ans << endl;
  return 0;
}
