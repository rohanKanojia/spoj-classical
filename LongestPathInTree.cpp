#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Graph {
  long long V;
  long long nEdges;
  list<long long> *adj;
public:
  Graph(long long V) : nEdges(0) {
    this->V = V;
    adj = new list<long long>[V];
  }
  void addEdge(long long v, long long w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
    nEdges++;
  }
  list<long long>& getNeighbours(long long v)   { return adj[v]; }
  long long getNodes() const                    { return V; }
  long long getEdges() const                    { return nEdges; }
};
long long longestPath(Graph& gg, long long start, long long& farthest);

int main() {
  long long nNodes;
  cin >> nNodes;

  Graph gg(nNodes);
  for(long long i = 0; i < nNodes-1; i++) {
    long long a, b;
    cin >> a >> b;
    gg.addEdge(a-1, b-1);
  }

  long long farthestNode;
  longestPath(gg, 0, farthestNode);

  cout << longestPath(gg, farthestNode, farthestNode) << endl;
  return 0;
}


long long longestPath(Graph& gg, long long start, long long& farthestNode) {
  stack<long long> ss;
  vector<bool> isVisited(gg.getNodes(), false);
  vector<long long> pathArr(gg.getNodes(), 0);

  ss.push(start);
  pathArr[start] = 0;

  while(!ss.empty()) {
    long long curNode = ss.top();
    isVisited[curNode] = true;
    ss.pop();

    list<long long> curNeighbours = gg.getNeighbours(curNode);

    for(auto i = curNeighbours.begin(); i != curNeighbours.end(); i++) {
      if(isVisited[*i] == false) {
        pathArr[*i] = 1 + pathArr[curNode];
        isVisited[*i] = true;
        ss.push(*i);
      }
    }
  }
  
  long long maxPath = pathArr[0];
  for(long long i = 1; i < gg.getNodes(); i++) {
    if(maxPath < pathArr[i]) {
      maxPath = pathArr[i];
      farthestNode = i;
    }
  }

  return maxPath;
}
