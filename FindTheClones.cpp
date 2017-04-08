#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
  while(true) {
    int N, M;
    cin >> N >> M;
    if(!N && !M)
      break;
    string ss;
    map<string, int> mm;
    for(int i = 0; i < N; i++) {
      cin >> ss;
      mm[ss]++;
    }
    vector<int> nCopied(N+1, 0);
    for(map<string, int>::iterator ii = mm.begin(); ii != mm.end(); ii++)
      nCopied[ii->second]++;

    for(int i = 1; i < N+1; i++)
      cout << nCopied[i] << endl;
  }
  return 0;
}
