#include <iostream>
#include <queue>
using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N, M, p;
    cin >> N >> M;
    
    queue<pair<int, int> > qq;
    priority_queue<int> pq;
    for(int i = 0; i < N; i++) {
      cin >> p;
      qq.push(make_pair(i, p));
      pq.push(p);
    }

    int nT = 0;
    pair<int, int> curJob;
    while(!qq.empty()) {
      curJob = qq.front();
      qq.pop();

      if(curJob.second != pq.top())
        qq.push(curJob);
      else {
        nT++;
        pq.pop();
        if(curJob.first == M) break;
      } 
    }
    cout << nT << endl;
  }
  return 0;
}
