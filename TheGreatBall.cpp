#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N, nPersons = 0;
    vector<long long> enter, exit;
    cin >> N;
    for(long long i = 0; i < N; i++) {
      long long start, end;
      cin >> start >> end;
      enter.push_back(start);
      exit.push_back(end);
    }
    sort(enter.begin(), enter.end());
    sort(exit.begin(), exit.end());
    
    long long enterI = 0, exitI = 0, ans = 0;
    while(enterI < enter.size() && exitI < exit.size()) {
      if(enter[enterI] < exit[exitI]) {
        enterI++;
        nPersons++;
      }
      else {
        exitI++;
        nPersons--; 
      }
      ans = std::max(nPersons, ans);
    }

    cout << ans << endl;
  }
  return 0;
}
