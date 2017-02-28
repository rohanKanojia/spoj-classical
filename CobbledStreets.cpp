#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Edge { long long start, end, wt; } Edge;
typedef struct Subset { long long parent, rank; } Subset;

class DisjointSet {
  vector<Subset> subsets;
public:
  DisjointSet(long long V) {
    for(long long i = 0; i < V; i++) {
      Subset aSubset;
      aSubset.parent = i;
      aSubset.rank = 0;
      subsets.push_back(aSubset);
    }
  }
  void Union(long long x, long long y) {
    long long xRt = Find(x);
    long long yRt = Find(y);

    if(subsets[xRt].rank < subsets[yRt].rank)
      subsets[xRt].parent = yRt;
    else if(subsets[xRt].rank > subsets[yRt].rank)
      subsets[yRt].parent = xRt;
    else {
      subsets[yRt].parent = xRt;
      subsets[xRt].rank++;
    }
  }
  long long Find(long long x) {
    if(subsets[x].parent != x)
      subsets[x].parent = Find(subsets[x].parent);
    return subsets[x].parent;
  }
};

class Graph {
  long long vertices;
  vector<Edge> edges;
public:
  Graph(long long V) : vertices(V) { }
  void addEdge(long long start, long long end, long long wt) {
    Edge aEdge;
    aEdge.start = start;
    aEdge.end = end;
    aEdge.wt = wt;
    
    edges.push_back(aEdge);
  }
  long long getNodes() const { return vertices; }
  long long getEdges() const { return edges.size(); }
  vector<Edge> getEdgesArr() { return edges; }
};

long long mstWt(Graph& gg);
bool myComp(Edge a1, Edge a2) { return a1.wt < a2.wt; }

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long price, N, E;
    cin >> price >> N >> E;

    Graph gg(N);
    for(long long i = 0; i < E; i++) {
      long long start, end, edgeWt;
      cin >> start >> end >> edgeWt;
      gg.addEdge(start-1, end-1, edgeWt);
    }

    long long ans = price * mstWt(gg);
    cout << ans << endl;
  }
  return 0;
}


long long mstWt(Graph& gg) {
  const long long V = gg.getNodes();
  long long minWt = 0;
  vector<Edge> edges = gg.getEdgesArr();

  sort(edges.begin(), edges.end(), myComp);

  DisjointSet ds(V);
  long long nEdges = 0;
  for(long long i = 0; nEdges < V-1; ) {
    Edge nextEdge = edges[i++];

    long long xSubset = ds.Find(nextEdge.start);
    long long ySubset = ds.Find(nextEdge.end);

    if(xSubset != ySubset) { // adding this edge won't cause cycle
      minWt += nextEdge.wt;
      nEdges++;
      ds.Union(xSubset, ySubset);
    }
  }
  return minWt;
}
