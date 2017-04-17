#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--) {
    map<string, int> mapGoals;
    for(int i = 0; i < 16; i++) {
      string t1, t2;
      int g1, g2;
      cin >> t1 >> t2 >> g1 >> g2;
      mapGoals[t1] += (g1 > g2 ? 1 : 0);
      mapGoals[t2] += (g1 < g2 ? 1 : 0);
    }

    map<string, int>::iterator ii = mapGoals.begin(); 
    string winnerTeam;
    int winGoals = 0;
    while(ii != mapGoals.end()) {
      if(winGoals < ii->second) {
        winGoals = ii->second;
        winnerTeam = ii->first;
      }
      ii++;
    }
    cout << winnerTeam << endl;
  }
  return 0;
}
