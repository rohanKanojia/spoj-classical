#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

void topologicalSort(set<int> adj[], vector<int>& inDegree, int N) {
  set<int> nodesToProcess;
  for(int i = 0; i < N; i++) {
    if(inDegree[i] == 0)
      nodesToProcess.insert(i);
  }

  while(!nodesToProcess.empty()) {
    int u = *(nodesToProcess.begin());
    nodesToProcess.erase(nodesToProcess.begin());
    cout << u+1 << " ";
    for(set<int>::iterator ii = adj[u].begin(); ii != adj[u].end(); ii++) {
      int v = *ii;
      inDegree[v]--;
      if(inDegree[v] == 0)
        nodesToProcess.insert(v);
    }
  }
  cout << endl;
}

int main() {
  int N, M;
  cin >> N >> M;
  set<int> adj[101];
  vector<int> inDegree(N, 0);
  for(int i = 0; i < M; i++) {
    int u, k;
    cin >> u >> k;
    for(int j = 0; j < k; j++) {
      int v;
      cin >> v;
      adj[v-1].insert(u-1);
    }
    inDegree[u-1] += k;
  }
  topologicalSort(adj, inDegree, N);
  return 0;
}
