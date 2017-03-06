#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define SIZE 3000
long long lcs[SIZE][SIZE];
long long longestCommonSubsequence(vector<long long>& agnes, vector<long long>& curRoute) {
  for(int i = 0; i <= agnes.size(); i++) {
    for(int j = 0; j <= curRoute.size(); j++) {
      if(i == 0 || j == 0)
        lcs[i][j] = 0;
      else if(agnes[i-1] == curRoute[j-1])
        lcs[i][j] = 1 + lcs[i-1][j-1];
      else
        lcs[i][j] = std::max(lcs[i-1][j], lcs[i][j-1]);
    }
  }
  return lcs[agnes.size()][curRoute.size()];
}

int main() {
  long long T;
  cin >> T;

  while(T--) {
    vector<long long> agnes;
    vector<vector<long long> > others;
    long long N;
    while(true) {
      cin >> N;
      if(N == 0)
        break;
      agnes.push_back(N);
    }
    while(true) {
      vector<long long> tmp;
      cin >> N;
      if(N == 0)
        break;
      tmp.push_back(N);
      while(true) {
        cin >> N;
        if(N == 0)
          break;
        tmp.push_back(N);
      }
      others.push_back(tmp);
    }

    long long ans = 0;
    for(long long i = 0; i < others.size(); i++) 
      ans = std::max(ans, longestCommonSubsequence(agnes, others[i]));
    cout << ans << endl;
  }
  return 0;
}
