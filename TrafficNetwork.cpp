#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000
typedef std::pair<int, int> Edge;

class Graph {
  int V;
public:
  std::vector<Edge> *adj;
  
  Graph(int nVertices)
    : V(nVertices), adj(new std::vector<Edge>[nVertices])  { }
  
  void addEdge(int from, int to, int weight)
    { adj[from].push_back(std::make_pair(weight, to)); } 
};

void dijkstra(int start, Graph& aGraph, std::vector<int>& dist, std::vector<bool>& isVisited) {
  std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge> > aPriorityQueue;
  dist[start] = 0;

  aPriorityQueue.push(std::make_pair(0, start));
  while(!aPriorityQueue.empty()) {
    int curNode = aPriorityQueue.top().second;
    aPriorityQueue.pop();

    if(!isVisited[curNode]) {
      isVisited[curNode] = true;
      for(int i = 0; i < aGraph.adj[curNode].size(); i++) {
        int aNode = aGraph.adj[curNode][i].second;
        int wt = aGraph.adj[curNode][i].first;

        if(!isVisited[aNode] && dist[aNode] > dist[curNode] + wt) {
          dist[aNode] = dist[curNode] + wt;
          aPriorityQueue.push(std::make_pair(dist[aNode], aNode));
        }
      }
    }
  }
}

int main() {
  int nTests;
  scanf("%d", &nTests);

  while(nTests--) {
    int N, E, K, S, T, start, end, wt;
    scanf("%d%d%d%d%d", &N, &E, &K, &S, &T);
    Graph aGraph(N), aTranspose(N);

    for(int i = 0; i < E; i++) {
      scanf("%d%d%d", &start, &end, &wt);

      aGraph.addEdge(start-1, end-1, wt);
      aTranspose.addEdge(end-1, start-1, wt); 
    }
    
    // Run dijkstra's algo on graph and it's transpose:
    std::vector<int> dist1(N, INF), dist2(N, INF);
    std::vector<bool> isVisited(N, false);

    dijkstra(S-1, aGraph, dist1, isVisited);
    std::fill(isVisited.begin(), isVisited.end(), false);
    dijkstra(T-1, aTranspose, dist2, isVisited);

    int shortestPath = INF;
    while(K--) {
      scanf("%d%d%d", &start, &end, &wt);
      // check if the edge's both ends make current path shorter or not
      // S --> start__end --> T
      // or
      // S --> end__start --> T
      shortestPath = std::min(shortestPath,
                              std::min(dist1[T-1],
                                std::min(dist1[start-1] + wt + dist2[end-1], dist1[end-1] + wt + dist2[start-1])
                              ));

    }
    printf("%d\n", shortestPath < INF ? shortestPath : -1);
  }
  return 0;
}
