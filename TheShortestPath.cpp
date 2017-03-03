#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

typedef pair<long long, long long> Edge;

class Graph {
  long long V;
  long long nEdges;
public:
  vector<Edge> *adj;
  Graph(long long V) : nEdges(0) {
    this->V = V;
    adj = new vector<Edge>[V];
  }
  void addEdge(long long v, long long w, long long wt) {
    adj[v].push_back(make_pair(w, wt));
    nEdges++;
  }
  long long getNodes() const                    { return V; }
  long long getEdges() const                    { return nEdges; }
  ~Graph() { delete[] adj; }
};
long long dijkstrasShortestPath(Graph& gg, long long start, long long end);
long long minDistance(vector<long long>& dist, vector<bool>& sptSet);

int main() {
  long long T;
  char cityName[1000], cityName1[1000];
  scanf("%lld", &T);

  while(T--) {
    unordered_map<string, long long> nameToIndex;
    long long N;
    scanf("%lld", &N);
    Graph gg(N);
    for(long long i= 0; i < N; i++) {
      scanf("%s", cityName);
      nameToIndex[string(cityName)] = i;
      long long E;
      scanf("%lld", &E);
      for(long long j = 0; j < E; j++) {
        long long a, wt;
        scanf("%lld%lld", &a, &wt);
        gg.addEdge(i, a-1, wt);
      }
    }

    long long Q;
    scanf("%lld", &Q);
    for(long long i = 0; i < Q; i++) {
      scanf("%s%s", cityName, cityName1);

      printf("%d\n", dijkstrasShortestPath(gg, nameToIndex[string(cityName)], 
        nameToIndex[string(cityName1)]));
    }
  }
  return 0;
}

long long dijkstrasShortestPath(Graph& gg, long long start, long long end) {
  const long long V = gg.getNodes();
  priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
  vector<long long> dist(V, INT_MAX);

  pq.push(make_pair(start, 0));
  dist[start] = 0;

  while(!pq.empty()) {
    long long u = pq.top().first;
    pq.pop();

    for(long long ii = 0; ii < gg.adj[u].size(); ii++) {
      long long v = gg.adj[u][ii].first;
      long long wt = gg.adj[u][ii].second;

      if(dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        pq.push(make_pair(v, dist[v]));
      }
    }
  }
  return dist[end];
}
