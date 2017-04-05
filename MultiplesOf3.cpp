#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 800001
typedef struct Node { int ones, zeroes, twos; } Node;
Node tree[SIZE];
int lazy[SIZE];

class SegmentTree {
  int size;
  Node mergeNodes(Node a, Node b) {
    Node res;
    res.ones = a.ones + b.ones;
    res.zeroes = a.zeroes + b.zeroes;
    res.twos = a.twos + b.twos;
    return res;
  }
public:
  SegmentTree(int sz) : size(sz) { 
    std::fill(lazy, lazy + 4*size, 0);
    buildTree(0, 0, size-1);
  }
  void buildTree(int curIndex, int start, int end) {
    if(start == end) {
      tree[curIndex].ones = tree[curIndex].twos = 0;
      tree[curIndex].zeroes = 1;
    }
    else {
      int l = curIndex*2 + 1;
      int r = curIndex*2 + 2;
      int mid = (start + end)/2;
      buildTree(l, start, mid);
      buildTree(r, mid+1, end);
      tree[curIndex] = mergeNodes(tree[l], tree[r]);
    }
  }
  int query(int ss, int se, int qs, int qe, int si) {
    if(lazy[si] != 0)
      updateNode(si);

    if(ss > se || ss > qe || se < qs)
      return 0;
    else if(ss >= qs && se <= qe) 
      return tree[si].zeroes;

    int l = (si*2 + 1);
    int r = (si*2 + 2);
    int mid = (ss + se)/2;
    
    if(qe <= mid)
      return query(ss, mid, qs, qe, l);
    else if(qs > mid)
      return query(mid+1, se, qs, qe, r);
    else
      return query(ss, mid, qs, qe, l) +
        query(mid+1, se, qs, qe, r);
  }
  void update(int si, int ss, int se, int us, int ue) {
    if(lazy[si])
      updateNode(si);
    if(ss > se || ss > ue || se < us)
      return;
    if(ss >= us && se <= ue) {
      lazy[si]++;
      updateNode(si);
    }
    else {
      int l = (si*2 + 1);
      int r = (si*2 + 2);
      int mid = (ss + se)/2;

      if(ue <= mid)
        update(l, ss, mid, us, ue);
      else if(us > mid)
        update(r, mid+1, se, us, ue);
      else {
        update(l, ss, mid, us, ue);
        update(r, mid+1, se, us, ue);
      }
      updateNode(l);
      updateNode(r);
      tree[si] = mergeNodes(tree[l], tree[r]);
    }
  }
  void updateNode(int index) {
    lazy[index] = lazy[index] % 3;
    if(lazy[index] == 1) {
      swap(tree[index].zeroes, tree[index].twos);
      swap(tree[index].ones, tree[index].twos);
    }
    else if(lazy[index] == 2) {
      swap(tree[index].zeroes, tree[index].ones);
      swap(tree[index].ones, tree[index].twos);
    }
    lazy[index*2+1] += lazy[index];
    lazy[index*2+2] += lazy[index];
    lazy[index] = 0;
  }
};

int main() {
  int N, Q;
  scanf("%d%d", &N, &Q);
  
  SegmentTree ss(N);
  for(int i = 0; i < Q; i++) {
    int op, a, b;
    scanf("%d%d%d", &op, &a, &b);

    if(op == 1)
      printf("%d\n", ss.query(0, N-1, a, b, 0));
    else
      ss.update(0, 0, N-1, a, b);
  }
  return 0;
}
