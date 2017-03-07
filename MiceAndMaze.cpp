#include <iostream>
#include <queue>
#include <climits>
#include <vector>
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
  int getNodes() { return V; }
  int getEdges() { return nEdges; }
  ~Graph() { delete[] adj; }
};
int dijkstrasShortestPath(Graph& gg, int start, int dist);

int main() {
  int N, T, E, nEdges;
  cin >> N >> E >> T;
  Graph gg(N);
  cin >> nEdges;
  for(int i = 0; i < nEdges; i++) {
    int a, b, wt;
    cin >> a >> b >> wt;
    gg.addEdge(a-1, b-1, wt);  
  }

  cout << dijkstrasShortestPath(gg, E-1, T) << endl;
  return 0;
}

int dijkstrasShortestPath(Graph& gg, int start, int minDistance) {
  const int V = gg.getNodes();
  priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
  vector<int> dist(V, INT_MAX);

  pq.push(make_pair(start, 0));
  dist[start] = 0;

  while(!pq.empty()) {
    int u = pq.top().first;
    pq.pop();

    for(int i = 0; i < gg.adj[u].size(); i++) {
      int v = gg.adj[u][i].first;
      int wt = gg.adj[u][i].second;

      if(dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        pq.push(make_pair(v, dist[v]));
      }
    }
  }
  
  int ans = 0;
  for(int i = 0; i < dist.size(); i++) {
    if(dist[i] <= minDistance) {
      ans++;
    }
  }
  return ans;
}
