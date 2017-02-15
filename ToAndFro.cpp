#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  long long N = 1;
  while(1) {
    cin >> N;
    if(N == 0) break;
    string ss;
    cin >> ss;
    vector<vector<char> > arr;
    
    for(long long i = 0; i < ss.length()/N; i++) {
      vector<char> aRow(N);
      for(long long j = 0; j < N; j++) {
        if(i%2 == 0)
          aRow[j] = ss[i*N + j];
        else
          aRow[j] = ss[i*N + N-1-j];
      }
      arr.push_back(aRow);
    }


    for(long long i = 0; i < N; i++) 
      for(long long j = 0; j < ss.length()/N; j++)
        cout << arr[j][i];
    cout << endl;
  }
  
  return 0;
}
