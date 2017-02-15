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
bool checkTree(Graph& gg);

int main() {
  long long nNodes, nEdges;
  cin >> nNodes >> nEdges;

  Graph gg(nNodes);
  for(long long i = 0; i < nEdges; i++) {
    long long a, b;
    cin >> a >> b;
    gg.addEdge(a-1, b-1);
  }

  cout << (checkTree(gg) ? "YES" : "NO") << endl;
  return 0;
}


bool checkTree(Graph& gg) {
  // For total connection. dfs from one node should reach all n nodes.
  stack<long long> ss;
  vector<bool> isVisited(gg.getNodes(), false);  
  long long nNodes = 0;

  ss.push(0);

  while(!ss.empty()) {
    long long curNode = ss.top();
    isVisited[0] = true;
    ss.pop();
    nNodes++;

    list<long long> curNeighbours = gg.getNeighbours(curNode);

    for(auto i = curNeighbours.begin(); i != curNeighbours.end(); i++) {
      if(isVisited[*i] == false) {
        isVisited[*i] = true;
        ss.push(*i);
      }
    }
  }

  return (nNodes == gg.getNodes()) && 
         (gg.getEdges() == gg.getNodes()-1);
}
