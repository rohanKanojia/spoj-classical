#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Edge { int start, end, wt; };
struct Subset { int parent, rank; };

class DisjointSet {
  vector<Subset> subsets;
public:
  DisjointSet(int V) {
    for(int i = 0; i < V; i++) {
      Subset aSubset;
      aSubset.parent = i;
      aSubset.rank = 0;
      subsets.push_back(aSubset);
    }
  }
  void Union(int x, int y) {
    int xRt = Find(x);
    int yRt = Find(y);

    if(subsets[xRt].rank < subsets[yRt].rank)
      subsets[xRt].parent = yRt;
    else if(subsets[xRt].rank > subsets[yRt].rank)
      subsets[yRt].parent = xRt;
    else {
      subsets[yRt].parent = xRt;
      subsets[xRt].rank++;
    }
  }
  int Find(int x) {
    if(subsets[x].parent != x)
      subsets[x].parent = Find(subsets[x].parent);
    return subsets[x].parent;
  }
};

class Graph {
  int vertices;
public:
  vector<Edge> edges;
  Graph(int V) : vertices(V) { }
  void addEdge(int start, int end, int wt) {
    Edge aEdge;
    aEdge.start = start;
    aEdge.end = end;
    aEdge.wt = wt;

    edges.push_back(aEdge);
  }
  int getNodes() const { return vertices; }
  int getEdges() const { return edges.size(); }
};
int getMstWt(Graph& gg);
bool myComp(Edge a1, Edge a2) { return a1.wt < a2.wt; }

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
    Graph gg(N);
    for(int i = 0; i < N; i++) {
      string ss;
      cin >> ss;
      int neighbours;
      cin >> neighbours;
      for(int j = 0; j < neighbours; j++) {
        int opVertex, wt;
        cin >> opVertex >> wt;

        gg.addEdge(i, opVertex-1, wt);
      }
    }

    cout << getMstWt(gg) << endl;
  }
  return 0;
}

int getMstWt(Graph& gg) {
  const int V = gg.getNodes();
  int minWt = 0;
  vector<Edge> edges = gg.edges;

  sort(edges.begin(), edges.end(), myComp);

  DisjointSet ds(V);
  int nEdges = 0;
  for(int i = 0; nEdges < V-1; ) {
    Edge nextEdge = edges[i++];

    int xSubset = ds.Find(nextEdge.start);
    int ySubset = ds.Find(nextEdge.end);

    if(xSubset != ySubset) {
      minWt += nextEdge.wt;
      nEdges++;
      ds.Union(xSubset, ySubset);
    }
  }
  return minWt;
}
