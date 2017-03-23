#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 100000

class SegmentTree {
  long long tree[4*SIZE], lazy[4*SIZE];
  long long size;
  long long mergeNodes(long long a, long long b)
    { return a + b; }
public:
  SegmentTree(long long sz) : size(sz) {
    std::fill(tree, tree+ 4*size, 0);
    std::fill(lazy, lazy+ 4*size, 0);
  }
  long long query(long long ss, long long se, long long qs, 
    long long qe, long long si) {
    if(lazy[si] != 0) {
      tree[si] = se-ss+1-tree[si];

      if(ss != se) {
        lazy[si*2 + 1] = !lazy[si*2+1];
        lazy[si*2 + 2] = !lazy[si*2+2];
      }
      lazy[si] = 0;
    }
    if(ss > se || ss > qe || se < qs)
      return 0;
    if(ss >= qs && se <= qe)
      return tree[si];

    long long l = si*2 + 1;
    long long r = si*2 + 2;
    long long mid = (ss+se)/2;

    if(qe <= mid)
      return query(ss, mid, qs, qe, l);
    else if(qs > mid)
      return query(mid+1, se, qs, qe, r);
    else
      return mergeNodes(query(ss, mid, qs, qe, l), query(mid+1, se, qs, qe, r));
  }
  void update(long long si, long long ss, long long se, long long us, long long ue) {
    if(lazy[si] != 0) {
      tree[si] = (se-ss+1-tree[si]);

      if(ss != se) {
        lazy[si*2+1] = !lazy[si*2+1];
        lazy[si*2+2] = !lazy[si*2+2];
      }
      lazy[si] = 0;
    }
    // out of range
    if(ss > se || ss > ue || se < us)
      return;
    // Current segment fully in range
    if(ss >= us && se <= ue) {
      tree[si] = (se-ss+1-tree[si]);

      if(ss != se) {
        lazy[si*2+1] = !lazy[si*2+1];
        lazy[si*2+2] = !lazy[si*2+2];
      }
    }
    else {
      long long mid = (ss+se)/2;
      update(si*2+1, ss, mid, us, ue);
      update(si*2+2, mid+1, se, us, ue);

      tree[si] = tree[si*2+1] + tree[si*2+2];
    }
  }
}; 

int main() {
  long long N, M;
  scanf("%lld%lld", &N, &M);

  SegmentTree st(N);
  while(M--) {
    long long op, a, b;
    scanf("%lld%lld%lld", &op, &a, &b);
    if(op == 0) 
      st.update(0, 0, N-1, a-1, b-1);
    else 
      printf("%lld\n", st.query(0, N-1, a-1, b-1, 0));
  }
  return 0;
}
