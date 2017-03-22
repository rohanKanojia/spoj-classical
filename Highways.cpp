#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

typedef pair<int, int> Edge;
class Graph {
  int V, nEdges;
public:
  vector<Edge> *adj;
  Graph(int V) : nEdges(0) {
    this->V = V;
    adj = new vector<Edge>[V];
  }
  void addEdge(int v, int w, int wt) {
    adj[v].push_back(make_pair(w, wt));
    adj[w].push_back(make_pair(v, wt));
    nEdges++;
  }
  int getNodes() const { return V;      }
  int getEdges() const { return nEdges; }
  ~Graph()             { delete[] adj;  }
};
int dijkstrasShortestPath(Graph& gg, int start, int end);

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N, nEdges, start, end;
    cin >> N >> nEdges >> start >> end;

    Graph gg(N);
    for(int i = 0; i < nEdges; i++) {
      int a, b, wt;
      cin >> a >> b >> wt;
      gg.addEdge(a-1, b-1, wt);
    }
    
    int ans = dijkstrasShortestPath(gg, start-1, end-1);
    if(ans >= 0)
      cout << ans << endl;
    else
      cout << "NONE\n";
  }
  return 0;
}

int dijkstrasShortestPath(Graph& gg, int start, int end) {
  const int V = gg.getNodes();
  priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
  vector<int> dist(V, INT_MAX);

  pq.push(make_pair(start, 0));
  dist[start] = 0;

  while(!pq.empty()) {
    int u = pq.top().first;
    pq.pop();

    for(int ii = 0; ii < gg.adj[u].size(); ii++) {
      int v = gg.adj[u][ii].first;
      int wt = gg.adj[u][ii].second;

      if(dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        pq.push(make_pair(v, dist[v]));
      }
    }
  }

  return dist[end] == INT_MAX ? -1 : dist[end];
}
