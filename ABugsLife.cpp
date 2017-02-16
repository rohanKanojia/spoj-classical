#include <cstdio>
#include <vector>
#include <list>
#include <queue>
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
bool isBipartite(Graph& gg);
bool isBipartiteUtil(Graph& gg, vector<long long>& colors);

int main() {
  long long T, nCase = 1;
  scanf("%lld", &T);
  while(T--) {
    long long N, E;
    scanf("%lld%lld", &N, &E);
    Graph gg(N);
    for(long long i = 0; i < E; i++) {
      long long a, b;
      scanf("%lld%lld", &a, &b);
      gg.addEdge(a-1, b-1);
    }

    printf("Scenario #%lld:\n", nCase++);
    if(!isBipartite(gg))
      printf("Suspicious bugs found!\n");
    else
      printf("No suspicious bugs found!\n");
  }
}

bool isBipartiteUtil(Graph& gg, vector<long long>& colors, long long src) {
  queue<long long> qq;
  colors[src] = 1;
  qq.push(src);
  
  while(!qq.empty()) {
    long long curNode = qq.front();
    qq.pop();
    list<long long> curNeighbours = gg.getNeighbours(curNode);
    list<long long>::iterator ii = curNeighbours.begin();
    while(curNeighbours.end() != ii) {
      if(colors[*ii] == -1) {
        colors[*ii] = 1 - colors[curNode];
        qq.push(*ii);
      }
      else if(colors[*ii] == colors[curNode])
        return false;
      ii++;
    }
  }
  return true;
}

bool isBipartite(Graph& gg) {
  vector<long long> colors(gg.getNodes(), -1);

  for(long long i = 0; i < gg.getNodes(); i++)
    if(colors[i] == -1 && isBipartiteUtil(gg, colors, i) == false)
      return false;
  return true;
}
