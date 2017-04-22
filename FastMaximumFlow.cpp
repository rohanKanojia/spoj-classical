// http://e-maxx.ru/algo/dinic
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_V 5009
long long capacity[MAX_V][MAX_V];
long long flow[MAX_V][MAX_V];
int dist[MAX_V], last[MAX_V], now[MAX_V];
vector<int> adj[MAX_V];
int q[MAX_V], N, M;
void addEdge(int u, int v, int c);
long long DinicMaxFlow();
long long dfs(long long curNode, long long curFlow);
bool bfs();

int main() {
  scanf("%d%d", &N, &M);

  int i, u, v, c;
  for(i = 0; i < M; i++) {
    scanf("%d%d%d", &u, &v, &c);
    addEdge(u, v, c);
  }
  printf("%lld\n", DinicMaxFlow());
  return 0;
}

void addEdge(int u, int v, int c) {
  if(capacity[u][v]) {
    capacity[u][v] += c;
    capacity[v][u] += c;
  }
  else if(u != v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] += c;
    capacity[v][u] += c;
  }
}

long long DinicMaxFlow() {
  long long nFlow = 0, curFlow;
  while(bfs()) {
    memset(now, 0, (N+1)*sizeof(now[0]));
    while(curFlow = dfs(1, 1e15))
      nFlow += curFlow;
  }
  return nFlow;
}

long long dfs(long long curNode, long long curFlow) {
  if(curNode == N) return curFlow;
  if(!curFlow)     return 0;

  for(; now[curNode] < adj[curNode].size(); now[curNode]++) {
    long long to = adj[curNode][now[curNode]];

    if(capacity[curNode][to] > flow[curNode][to] && dist[to] == dist[curNode]+1) {
      
      curFlow = curFlow > (capacity[curNode][to]-flow[curNode][to]) ? 
        (capacity[curNode][to]-flow[curNode][to]) : curFlow;
      int aFlow = dfs(to, curFlow);

      if(aFlow > 0) {
        flow[curNode][to] += aFlow;
        flow[to][curNode] -= aFlow;
        return aFlow;
      }
    }
  }
  return 0;
}

bool bfs() {
  int curNode = 1, qH = 0, qT = 0;
  memset(dist, -1, sizeof(dist[0])*(N+1));
  q[qT++] = curNode;
  dist[curNode] = 0;
  
  while(qH < qT) { 
    int v = q[qH++];
    for(int i = 0; i < adj[v].size(); i++) {
      int to = adj[v][i];
      if(dist[to] == -1 && flow[v][to] < capacity[v][to]) {
        q[qT++] = to;
        dist[to] = dist[v] + 1;
      }
    }
  }
  return dist[N] != -1;
}
