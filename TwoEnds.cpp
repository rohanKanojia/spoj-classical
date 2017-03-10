#include <iostream>
#include <vector>
using namespace std;

long long dp[1001][1001];
long long checkOptimal(vector<long long>& arr, long long start, long long end);

int main() {
  long long nCase = 1;
  while(true) {
    long long N, sum = 0;
    cin >> N;
    if(N == 0)
      break;
    vector<long long> arr(N);
    for(long long i= 0; i < N; i++)
      cin >> arr[i], sum += arr[i];

    for(long long i = 0; i <= N; i++)
      for(long long j = 0; j <= N; j++)
        dp[i][j] = -1;

    long long firstPlayer = checkOptimal(arr, 0, arr.size()-1);
    long long secondPlayer = sum - firstPlayer;
    long long ans = firstPlayer - secondPlayer;
    cout << "In game " << nCase++ <<
      ", the greedy strategy might lose by as many as " << ans << " points.\n";
  }
  return 0;
}

long long checkOptimal(vector<long long>& arr, long long start, long long end) {
  if(start > end)
    return 0;
  else if(dp[start][end] == -1) {
    dp[start][end] = std::max(
      (arr[start+1] >= arr[end] ? 
        arr[start] + checkOptimal(arr, start+2, end) : arr[start] + checkOptimal(arr, start+1, end-1)),
      
      (arr[start] >= arr[end-1] ? 
        arr[end] + checkOptimal(arr, start+1, end-1) : arr[end] + checkOptimal(arr, start, end-2))
    );
  }
  return dp[start][end];
}
