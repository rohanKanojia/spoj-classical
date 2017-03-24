// Source : https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
const int INF = INT_MAX;
const int MAX = 1<<14;
const int LOG = 14;

vector<pii> G[MAX];
int root[MAX][LOG], dist[MAX], pi[MAX], Level[MAX];

void dfs(int par, int u, int depth) {
  int sz = G[u].size();
  Level[u] = depth;
  for(int i = 0; i < sz; i++) {
    int v = G[u][i].first; // other vertex
    int w = G[u][i].second; // cost
    if(v != par) {
      dist[v] = dist[u] + w;
      pi[v] = u;
      dfs(u, v, depth+1);
    }
  }
}

void calcRoot(int n) {
  memset(root, -1, sizeof(root));
  // first ancestor of every node i is pi[i]
  for(int i = 1; i <= n; i++)
    root[i][0] = pi[i];
  // bottom up dp
  for(int j = 1; (1<<j) < n; j++) {
    for(int i = 1; i <= n; i++) {
      if(root[i][j-1] != -1)
        root[i][j] = root[root[i][j-1]][j-1];
    }
  }
}

int lca(int p, int q) {
  int i, logVal;
  if(Level[p] < Level[q]) // if p is on a higher level than q
    swap(p, q);
  for(logVal = 1; (1<<logVal) <= Level[p]; logVal++); // Compute log(Level[p])
  logVal--;
  for(i = logVal; i >= 0; i--)         // We find the ancestor of node p situated on the same level
    if(Level[p] - (1<<i) >= Level[q])  // with q using values in p
      p = root[p][i];                  

  if(p == q)
    return p;

  for(i = logVal; i >= 0; i--) {
    if(root[p][i] != -1 && root[p][i] != root[q][i])
      p = root[p][i], q = root[q][i];
  }
 return pi[p];
}

int find(int p, int t) {
  int i, logVal;
  for(logVal = 1; (1<<logVal) <= Level[p]; logVal++);
  logVal--;
  for(i = logVal; i >= 0; i--) {
    if(Level[p] - (1<<i) >= t)
      p = root[p][i];
  }
  return p;
}

int main() {
  int T;
  char query[10];
  scanf("%d", &T);
  
  while(T--) {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
      G[i].clear();
      dist[i] = 0;
      pi[i] = -1;
    }
    for(int i = 1; i < N; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      G[u].push_back(pii(v, w));
      G[v].push_back(pii(u, w));
    }
    dist[1] = 0;
    dfs(-1, 1, 0); // set level wise depth
    calcRoot(N);

    while(true) {
      scanf("%s", query);
      if(query[1] == 'O')
        break;
      int start, end;
      scanf("%d%d", &start, &end);
      int ancestor = lca(start, end);

      if(query[1] == 'I')
        printf("%d\n", dist[start]+dist[end]-2*dist[ancestor]);
      else if(query[1] == 'T') {
        int k, v;
        scanf("%d", &k);
        if(Level[start]-Level[ancestor]+1 >= k)
          v = find(start, Level[start]-k+1);
        else
          v = find(end, 2*Level[ancestor]+k-Level[start]-1);
        
        printf("%d\n", v);
      }
    }
  }
  return 0;
}
