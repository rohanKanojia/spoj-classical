#include <iostream>
#include <climits>
#include <vector>
#include <unistd.h>
#include <algorithm>
using namespace std;

#define SIZE 40001

class Graph {
  int nVertices, E, start, dest;
  int capacity[SIZE], to[SIZE], next[SIZE];
  int last[201];
  bool isVisited[201];
public:
  Graph(int V) : nVertices(V), E(0) {
    std::fill(last, last+201, -1);
    std::fill(isVisited, isVisited+201, false);
    std::fill(capacity, capacity+SIZE, 0);
  }
  void addEdge(int u, int v, int uv, int vu) {
    to[E] = v;
    capacity[E] = uv;
    next[E] = last[u];
    last[u] = E++;

    to[E] = u;
    capacity[E] = vu;
    next[E] = last[v];
    last[v] = E++;
  }
  int dfs(int curNode, int flow) {
    if(curNode == dest || flow <= 0) return flow;
    if(isVisited[curNode]) return 0;
    
    isVisited[curNode] = true;

    for(int i = last[curNode]; i != -1; i = next[i]) {
      int iFlow = dfs(to[i], std::min(flow, capacity[i]));

      
      if(iFlow > 0) {
        capacity[i] -= iFlow;
        capacity[i^1] += iFlow;
        return iFlow;
      }
    }
    return 0;
  }
  int maxFlow(int source, int sink) {
    int aFlow = 0;
    start = source, dest = sink;

    while(true) {
      std::fill(isVisited, isVisited+nVertices+1, false);
      int curFlow = dfs(start, INT_MAX);
      if(curFlow == 0)
        break;
      aFlow += curFlow;
    }
    return aFlow;
  }
};

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
    Graph aGraph(N);
    for(int i = 0; i < N-1; i++) {
      int nEdges;
      cin >> nEdges;
      for(int j = 0; j < nEdges; j++) {
        int aNode;
        cin >> aNode;
        aGraph.addEdge(i, aNode-1, (i == 0 || aNode == N) ? 1  : INT_MAX, 0);
      }
    }

    cout << aGraph.maxFlow(0, N-1) << endl;
  }
  return 0;
}
