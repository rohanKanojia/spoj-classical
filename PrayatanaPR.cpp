#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

class Graph {
  int V, nEdges;
public:
  vector<int> *adj;
  Graph(int V) : nEdges(0) {
    this->V = V;
    adj = new vector<int>[V];
  }
  void addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
    nEdges++;
  }
  int getNodes() { return V; }
  int getEdges() { return nEdges; }
  ~Graph() { delete[] adj; }
};
int connectedComponents(Graph& gg, vector<bool>& isVisited, int start);

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N, nEdges;
    scanf("%d", &N);
    Graph gg(N);
    vector<bool> isVisited(N, false);
    scanf("%d", &nEdges);

    while(nEdges--) {
      int a, b;
      scanf("%d%d", &a, &b);
      gg.addEdge(a, b);
    }
    int nInformed = 0;
    for(int i = 0; i < N; i++) {
      if(isVisited[i] == false) {
        nInformed++;
        connectedComponents(gg, isVisited, i);
      }
    }
    printf("%d\n", nInformed);
  }
  return 0;
}

int connectedComponents(Graph& gg, vector<bool>& isVisited, int start) {
  int nElements = 0;
  stack<int> ss;
  ss.push(start);

  while(!ss.empty()) {
    int u = ss.top();
    isVisited[u] = true;
    ss.pop();
    nElements++;

    for(int i = 0; i < gg.adj[u].size(); i++) {
      if(isVisited[gg.adj[u][i]] == false)
        ss.push(gg.adj[u][i]);
    }
  }
  return nElements;
}
