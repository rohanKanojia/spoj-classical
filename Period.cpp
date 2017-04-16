#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int T, nCase = 1;
  cin >> T;

  while(T--) {
    int N;
    string pattern;
    cin >> N >> pattern;
    vector<int> F(N+1, 0);

    for(int i = 2; i <= N; i++) {
      int j = F[i-1]; // largest next partial match
                      // of string under index i-1
      while(true) {
        if(pattern[j] == pattern[i-1]) {
          F[i] = j+1;
          break;
        }
        if(j == 0) {
          F[i] = 0;
          break;
        }
        j = F[j]; // go to next best candidate for partial match
      }
    }

    cout << "Test case #" << nCase++ << endl;
    for(int i = 2; i <= N; i++) {
      if(F[i] && i%(i-F[i]) == 0)
        cout << i << " " << i/(i-F[i]) << endl;
    }
  }
  return 0;
}
