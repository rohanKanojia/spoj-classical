#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myComp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}

int main() {
  long long T;
  cin >> T;

  while(T--) {
    vector<pair<long long, long long> > arr;

    long long N;
    cin >> N;
    for(long long i = 0; i < N; i++) {
      long long a, b;
      cin >> a >> b;
      arr.push_back(make_pair(a, b));
    }

    std::sort(arr.begin(), arr.end(), myComp);

    long long nTasks = 1, prev = 0;
    for(long long i = 1; i < N; i++) {
      if(arr[i].first >= arr[prev].second) {
        nTasks++;
        prev = i;
      }
    }
    cout << nTasks << endl;
  }
  return 0;
}
