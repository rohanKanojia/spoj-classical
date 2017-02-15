#include <iostream>
#include <vector>
using namespace std;

bool checkBoundaries(long long r, long long c, long long nRows, long long nCols) {
  return r >= 0 && r < nRows && c >= 0 && c < nCols;
}

long long stonesFromPoint(vector<vector<long long> >& arr, long long r, long long c) {
  long long maxVal = 0;
  if(checkBoundaries(r-1, c, arr.size(), arr[0].size())) {
    maxVal = std::max(maxVal, arr[r-1][c]);
  }
  if(checkBoundaries(r-1, c-1, arr.size(), arr[0].size())) {
    maxVal = std::max(maxVal, arr[r-1][c-1]);
  }
  if(checkBoundaries(r-1, c+1, arr.size(), arr[0].size())) {
    maxVal = std::max(maxVal, arr[r-1][c+1]);
  }
  return maxVal;
}

long long getMaxStones(vector<vector<long long> >& arr, long long nRows, long long nCols) {
  vector<vector<long long> > stones(nRows, vector<long long>(nCols, 0));
  long long ans = 0;

  for(long long i = 0; i < nRows; i++) {
    for(long long j = 0; j < nCols; j++) {
      stones[i][j] = arr[i][j] + stonesFromPoint(stones, i, j);
      
      if(i == nRows-1) {
        ans = std::max(ans, stones[i][j]);
      }
    }
  }

  return ans;
}


int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long nRows, nCols;
    cin >> nRows >> nCols;

    vector<vector<long long> > arr(nRows, vector<long long>(nCols));

    for(long long i = 0; i < nRows; i++)
      for(long long j = 0; j < nCols; j++)
        cin >> arr[i][j];


    cout << getMaxStones(arr, nRows, nCols) << endl;
  }
  return 0;
}
