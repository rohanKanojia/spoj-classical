// Done following anudeep's blog : https://blog.anudeep2011.com/heavy-light-decomposition/ 
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define N 10001
#define M 14

vector<int> adj[N], costs[N], index[N];
int baseArray[N], ptr;
int chainNo, chainIndex[N], chainHead[N], posInBase[N];
int depth[N], pa[M][N], otherEnd[N], subsize[N];
int st[N*6], qt[N*6];

void buildTree(int cur, int start, int end) {
  if(start == end-1) {
    st[cur] = baseArray[start];
    return;
  }
  int c1 = cur*2;
  int c2 = cur*2 + 1;

  int mid = (start+end)/2;

  buildTree(c1, start, mid);
  buildTree(c2, mid, end);
  st[cur] = std::max(st[c1], st[c2]);
}

void update(int cur, int start, int end, int x, int val) {
  if(start > x || end <= x)
    return;
  if(start == x && start == end-1) {
    st[cur] = val;
    return;
  }
  int c1 = 2*cur;
  int c2 = 2*cur+1;
  int mid = (start+end)/2;

  update(c1, start, mid, x, val);
  update(c2, mid, end, x, val);

  st[cur] = std::max(st[c1], st[c2]);
}

void query(int cur, int start, int end, int S, int E) {
  if(start >= E || end <= S) {
    qt[cur] = -1;
    return;
  }
  if(start >= S && end <= E) {
    qt[cur] = st[cur];
    return;
  }

  int c1 = 2*cur;
  int c2 = 2*cur+1;
  int mid = (start+end)/2;
  query(c1, start, mid, S, E);
  query(c2, mid, end, S, E);
  qt[cur] = std::max(qt[c1], qt[c2]);
}

int queryUp(int u, int v) {
  if(u == v)
    return 0;
  int uchain, vchain = chainIndex[v], ans = -1;

  while(true) {
    uchain = chainIndex[u];
    if(uchain == vchain) {
      if(u == v)
        break;
      query(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
      if(qt[1] > ans)
        ans = qt[1];
      break;
    }
    query(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
    if(qt[1] > ans)
      ans = qt[1];
    u = chainHead[uchain];
    u = pa[0][u];
  }
  return ans;
}

int LCA(int u, int v) {
  if(depth[u] < depth[v])
    swap(u, v);
  int diff = depth[u] - depth[v];
  for(int i = 0; i < M; i++) {
    if((diff>>i)&1) {
      u = pa[i][u];
    }
  }
  if(u == v)
    return u;
  for(int i = M-1; i >= 0; i--) 
    if(pa[i][u] != pa[i][v]) {
      u = pa[i][u];
      v = pa[i][v];
    }
  return pa[0][u];
}

void queryRange(int u, int v) {
  int lca = LCA(u, v);
  printf("%d\n", max(queryUp(u, lca), queryUp(v, lca)));
}

void change(int i, int val) {
  int u = otherEnd[i];
  update(1, 0, ptr, posInBase[u], val);
}

void HLD(int curNode, int cost, int prev) {
  if(chainHead[chainNo] == -1)
    chainHead[chainNo] = curNode;

  chainIndex[curNode] = chainNo;
  posInBase[curNode] = ptr;
  baseArray[ptr++] = cost;

  int sc = -1, nCost;
  for(int i = 0; i < adj[curNode].size(); i++) {
    if(adj[curNode][i] != prev) {
      if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
        sc = adj[curNode][i];
        nCost = costs[curNode][i];
      }
    }
  }

  if(sc != -1)
    HLD(sc, nCost, curNode);

  for(int i = 0; i < adj[curNode].size(); i++) {
    if(adj[curNode][i] != prev && sc != adj[curNode][i]) {
      chainNo++;
      HLD(adj[curNode][i], costs[curNode][i], curNode);
    }
  }
}

void dfs(int cur, int prev, int _depth=0) {
  pa[0][cur] = prev;
  depth[cur] = _depth;
  subsize[cur] = 1;
  for(int i = 0; i < adj[cur].size(); i++) {
    if(adj[cur][i] != prev) {
      otherEnd[index[cur][i]] = adj[cur][i];
      dfs(adj[cur][i], cur, _depth+1);
      subsize[cur] += subsize[adj[cur][i]];
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    ptr = 0;
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
      adj[i].clear();
      costs[i].clear();
      index[i].clear();
      chainHead[i] = -1;
      for(int j = 0; j< M; j++)
        pa[j][i] = -1;
    }

    for(int i = 1; i < n; i++) {
      int u,v, c;
      scanf("%d%d%d", &u, &v, &c);
      u--, v--;
      adj[u].push_back(v);
      costs[u].push_back(c);
      index[u].push_back(i-1);
      adj[v].push_back(u);
      costs[v].push_back(c);
      index[v].push_back(i-1);
    }

    chainNo = 0;
    dfs(0, -1);
    HLD(0, -1, -1);
    buildTree(1, 0, ptr);

    for(int i = 1; i < M; i++)
      for(int j = 0; j < n; j++)
        if(pa[i-1][j] != -1)
          pa[i][j] = pa[i-1][pa[i-1][j]];

    while(true) {
      char s[100];
      scanf("%s", s);
      if(s[0] == 'D')
        break;

      int a, b;
      scanf("%d%d", &a, &b);
      if(s[0] == 'Q')
        queryRange(a-1, b-1);
      else
        change(a-1, b);
    }
  }
  return 0;
}
