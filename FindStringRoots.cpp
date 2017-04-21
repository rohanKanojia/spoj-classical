#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  while(true) {
    string aStr;
    cin >> aStr;
    if(aStr == "*") break;

    int N = aStr.length(), k = 0, ans = 1;
    vector<int> F(N+1, 0);
    for(int i = 2; i <= N; i++) {
      int j = F[i-1];

      while(true) {
        if(aStr[j] == aStr[i-1]) {
          F[i] = j+1;
          break;
        }
        if(j == 0) {
          F[i] = 0;
          break;
        }
        j = F[j];
      }
    }

    int subLen = N - F[N];

    if(subLen < N && N%subLen == 0)
      ans = N/subLen;
    cout << ans << endl;
  }
  return 0;
}
