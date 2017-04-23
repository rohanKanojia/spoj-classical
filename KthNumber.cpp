#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int MAX_N = 111111;
int coords[MAX_N], aList[MAX_N];

class Node {
public:
  Node *left, *right;
  int sum;
  Node(Node *l, Node *r, int cnt) : sum(cnt), left(l), right(r) { }
}; 

Node* version[MAX_N];
Node* aNullNode = new Node(NULL, NULL, 0);

Node *update(Node *v, int vl, int vr, int x) {
  if(vl <= x && x < vr) {
    if(vl+1 == vr) 
      return new Node(aNullNode, aNullNode, (v->sum) + 1);

    int mid = (vl + vr)>>1;
    return new Node(update(v->left, vl, mid, x),
      update(v->right, mid, vr, x),
      (v->sum)+1
    );
  }
  return v;
}

int findNthNode(Node *u, Node *v, int vl, int vr, int k) {
  if(vl+1 == vr) return vl;

  int mid = (vl+vr)>>1;
  int sum = u->left->sum - v->left->sum;
  if(sum >= k)
    return findNthNode(u->left, v->left, vl, mid, k);
  return findNthNode(u->right, v->right, mid, vr, k-sum);
}

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  map<int, int> mm;
  for(int i = 0; i < N; i++) {
    scanf("%d", &aList[i]);
    mm[aList[i]];
  }

  // perform coordinate compression
  int nRank = 0;
  map<int, int>::iterator ii = mm.begin();
  for(; ii != mm.end(); ii++) {
    mm[ii->first] = nRank;
    coords[nRank] = ii->first;
    nRank++;
  }


  aNullNode->left = aNullNode->right = aNullNode;
  for(int i = 0; i < N; i++) {
      version[i] = update((i == 0 ? aNullNode : version[i-1]), 0, nRank, mm[aList[i]]);
  }

  for(int i = 0; i < M; i++) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    l--; r--;
    
    printf("%d\n", coords[
      findNthNode(version[r], 
      (l == 0 ? aNullNode : version[l-1]), 0, nRank, k)]);
  }
  return 0;
}
