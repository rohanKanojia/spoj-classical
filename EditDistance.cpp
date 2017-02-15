#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long editDistance(string& a, string& b) {
  long long nA = a.length(), nB = b.length();

  vector< vector<long long> > distances(nA+1, vector<long long>(nB+1));

  for(long long i = 0; i < nA+1; i++) {
    for(long long j = 0; j < nB+1; j++) {
      if(i == 0)
        distances[i][j] = j;
      else if(j == 0)
        distances[i][j] = i;
      else {
        long long delta = (a[i-1] != b[j-1]);

        distances[i][j] = std::min(delta + distances[i-1][j-1],
                            std::min(1 + distances[i-1][j], 1 + distances[i][j-1]));
      }
    }
  }

  return distances[nA][nB];
}

int main() {
  long long T;
  cin >> T;

  while(T--) {
    string a, b;
    cin >> a >> b;

    cout << editDistance(a, b) << endl;
  }
  return 0;
}
