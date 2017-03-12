#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  while(true) {
    long long N;
    cin >> N;
    if(N == 0) break;

    vector<long long> gasStations(N);
    for(long long i = 0; i < N; i++)
      cin >> gasStations[i];
    sort(gasStations.begin(), gasStations.end());
    gasStations.push_back(gasStations[N-1] + 2*(1422-gasStations[N-1]));

    bool bPossible = true;
    for(long long i = 0; i < N; i++) {
      if(gasStations[i+1] - gasStations[i] > 200) {
        bPossible = false;
        break;
      }
    }

    cout << (bPossible ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  }
  return 0;
}
