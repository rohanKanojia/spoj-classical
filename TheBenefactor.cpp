#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Edge;
class Graph {
  int nNodes, nEdges;
  vector<Edge> *adj;
public:
  Graph(int N) : nNodes(N) { adj = new vector<Edge>[N]; }
  void addEdge(int a, int b, int wt) {
    adj[a].push_back(make_pair(b, wt));
    adj[b].push_back(make_pair(a, wt));
  }
  int getNodes() { return nNodes; }
  ~Graph()       { delete[] adj;  }
  pair<int, int> bfs(int start) {
    vector<int> dist(nNodes, -1);

    queue<int> qq;
    qq.push(start);
    dist[start] = 0;

    while(!qq.empty()) {
      int curNode = qq.front();
      qq.pop();

      for(int i = 0; i < adj[curNode].size(); i++) {
        if(dist[adj[curNode][i].first] == -1) {
          qq.push(adj[curNode][i].first);
          dist[adj[curNode][i].first] = dist[curNode] + adj[curNode][i].second;
        }
      }
    }

    pair<int, int> retPair(make_pair(0, 0));
    for(int i = 0; i < nNodes; i++) {
      if(dist[i] > retPair.second) {
        retPair.first = i;
        retPair.second = dist[i];
      }
    }
    return retPair;
  }
};
int getLongestPath(Graph& gg);

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
    Graph gg(N);
    for(int i = 0; i < N-1; i++) {
      int a, b, wt;
      cin >> a >> b >> wt;
      gg.addEdge(a-1, b-1, wt);
    }
    cout << getLongestPath(gg) << endl;
  }
  return 0;
}

int getLongestPath(Graph& gg) {
  pair<int, int> firstTraversal, secondTraversal;

  firstTraversal = gg.bfs(0);
  secondTraversal = gg.bfs(firstTraversal.first);
  return secondTraversal.second;
}
