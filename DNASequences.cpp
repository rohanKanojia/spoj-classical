#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs[1010][1010], cont[1010][1010];

int main() {
  while(true) {
    int K;
    string s, t;
    cin >> K;
    if(!K) break;

    cin >> s >> t;
    cont[0][0] = 0;
    for(int i = 0; i < s.size(); i++)
      lcs[i][0] = lcs[0][i] = 0;

    for(int i = 1; i <= s.size(); i++) {
      for(int j = 1; j <= t.size(); j++) {
        lcs[i][j] = std::max(lcs[i-1][j], lcs[i][j-1]);
        if(s[i-1] == t[j-1])
          cont[i][j] = 1 + cont[i-1][j-1];
        else
          cont[i][j] = 0;

        if(cont[i][j] >= K) {
          for(int z = K; z <= cont[i][j]; z++)
            lcs[i][j] = std::max(lcs[i][j], lcs[i-z][j-z] + z);
        }
      }
    }
    cout << lcs[s.size()][t.size()] << endl;
  }
  return 0;
}
