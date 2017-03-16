#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string bfs(int N);
vector<int> remainderFrom(20001), addedValue(20001);

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;

    fill(remainderFrom.begin(), remainderFrom.end(), -1);
    cout << bfs(N) << endl;
  }
  return 0;
}

string bfs(int N) {
  queue<int> qq;
  qq.push(1);
  remainderFrom[1] = 0;

  while(!qq.empty()) {
    int curRemainder = qq.front();
    qq.pop();

    if(curRemainder == 0) { /* ans found */
      string ss;
      while(remainderFrom[curRemainder]) {
        ss += ('0' + addedValue[curRemainder]);
        curRemainder = remainderFrom[curRemainder];
      }
      ss += '1';
      reverse(ss.begin(), ss.end());
      return ss;
    }
    
    int state = (curRemainder * 10) % N;
    if(remainderFrom[state] == -1) {
      qq.push(state);
      remainderFrom[state] = curRemainder;
      addedValue[state] = 0;
    }

    state = (curRemainder * 10 + 1) % N;
    if(remainderFrom[state] == -1) {
      qq.push(state);
      remainderFrom[state] = curRemainder;
      addedValue[state] = 1;
    }
  }
}
