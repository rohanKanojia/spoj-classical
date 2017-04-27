#include <iostream>
#include <string>
#include <vector>
using namespace std;

void KmpFailureFunction(string ss, vector<int>& F) {
  F[0] = 0;

  for(int i = 1; i < ss.size(); i++) {
    int k = F[i-1];
    while(k > 0 && ss[k] != ss[i])
      k = F[k-1];
    if(ss[k] == ss[i])
      k++;
    F[i] = k;
  }
}

int main() {
  string ss;

  while(cin >> ss) {
    string revSS = string(ss.rbegin(), ss.rend());

    vector<int> F(ss.size());
    KmpFailureFunction(revSS, F);

    int k = 0;
    for(int i = 0; i < ss.size(); i++) {
      while(k > 0 && revSS[k] != ss[i])
        k = F[k-1];
      if(revSS[k] == ss[i])
        k++;
      if(i != ss.size()-1 && k == ss.size())
        k = F[ss.size()-1];
    }
    cout << ss;
    for(int i = ss.size()-1-k; i >= 0; i--)
      cout << ss[i];
    cout << endl;
  }
  return 0;
}
