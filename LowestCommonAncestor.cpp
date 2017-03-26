#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;
const int MAX = 1<<14;
const int LOG = 14;

vector<int> G[MAX];
int root[MAX][LOG],  pi[MAX], Level[MAX];

void dfs(int parent, int curNode, int depth) {
  Level[curNode] = depth;

  for(int i = 0; i < G[curNode].size(); i++) {
    int v = G[curNode][i];

    if(v != parent) {
      pi[v] = curNode;
      dfs(curNode, v, depth+1);
    }
  }
}

void calcRoot(int n) {
  memset(root, -1, sizeof(root));

  for(int i = 1; i <= n; i++)
    root[i][0] = pi[i];

  for(int j = 1; (1<<j) < n; j++) {
    for(int i = 1; i <= n; i++) {
      if(root[i][j-1] != -1)
        root[i][j] = root[root[i][j-1]][j-1];
    }
  }
}

int lca(int p, int q) {
  int i, logVal;
  if(Level[p] < Level[q])
    swap(p, q);
  for(logVal = 1; (1<<logVal) <= Level[p]; logVal++);
  logVal--;
  for(i = logVal; i >= 0; i--) 
    if(Level[p] - (1<<i) >= Level[q])
      p = root[p][i];

  if(p == q)
    return p;

  for(i = logVal; i >= 0; i--) {
    if(root[p][i] != -1 && root[p][i] != root[q][i])
      p = root[p][i], q = root[q][i];
  }
  return pi[p];
}

int main() {
  int T, nCase = 1;
  scanf("%d", &T);

  while(T--) {
    int N, neighbours, j, Q;
    scanf("%d", &N);
    for(int i = 0; i <= N; i++) {
      G[i].clear();
      pi[i] = -1;
    }
    for(int i = 1; i <= N; i++) {
      scanf("%d", &neighbours);
      while(neighbours--) {
        scanf("%d", &j);
        G[i].push_back(j);
        G[j].push_back(i);
      }
    }
    dfs(-1, 1, 0);
    calcRoot(N);

    scanf("%d", &Q);
    printf("Case %d:\n", nCase++);
    while(Q--) {
      int u, v;
      scanf("%d%d", &u, &v); 
      int ancestor = lca(u, v);

      printf("%d\n", ancestor);
    }
  }
  return 0;
}
