#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
    vector<pair<int, int> > arr(N);
    for(int i = 0; i < N; i++)
      cin >>arr[i].first >> arr[i].second;

    int dIndex = 0, dr = 0;
    for(int i = 0; i < N; i++) {
      if(dr < arr[i].first) {
        dr = arr[i].first;
        dIndex = i;
      }
    }

    int maxOuterRadius = 0;
    for(int i = 0; i < N; i++) {
      if(i != dIndex)
        maxOuterRadius = std::max(arr[i].second, maxOuterRadius);
    }

    cout << (maxOuterRadius < dr ? dIndex+1 : -1) << endl;
  }
  return 0;
}
