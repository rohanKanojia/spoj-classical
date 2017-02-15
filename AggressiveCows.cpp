#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
using namespace std;

long long binarySearch(vector<long long>& arr, long long nCows);
long long placeCows(vector<long long>& arr, long long distance);

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N, C;
    cin >> N >> C;

    vector<long long> arr(N);
    for(long long i = 0; i < N; i++)
      cin >> arr[i];

    sort(arr.begin(), arr.end());

    cout << binarySearch(arr, C) << endl;

  }
  return 0;
}

long long binarySearch(vector<long long>& arr, long long nCows) {
  long long start = 1, end = arr.back()+1;

  while(start+2 <= end) {
    long long mid = start + (end-start)/2;

    if(placeCows(arr, mid) >= nCows) {
      start = mid;
    }
    else {
      end = mid;
    }
  }

  return start;
}

long long placeCows(vector<long long>& arr, long long distance) {
  long long nCows = 1, curStall = 1, lastPlaced = 0;

  while(curStall < arr.size()) {
    if(arr[curStall]-arr[lastPlaced] >= distance) {
      nCows++;
      lastPlaced = curStall;
    }
    curStall++;
  }
  return nCows;
}
