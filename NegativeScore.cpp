#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 100000

class SegmentTree {
  int tree[4*SIZE];
  int parents[SIZE];
  vector<int> elements;
  int size;
  int mergeNodes(int a, int b) { return std::min(a, b); }
public:
  SegmentTree(vector<int> arr) : size(arr.size()) {
    elements = arr;
    buildTree(0, 0, size-1);
  }
  void buildTree(int curNode, int start, int end) {
    if(start == end) {
      tree[curNode] = elements[start];
      parents[start] = curNode;
    }
    else {
      int l = curNode*2 + 1;
      int r = curNode*2 + 2;

      int mid = (start+end)/2;
      buildTree(l, start, mid);
      buildTree(r, mid+1, end);

      tree[curNode] = mergeNodes(tree[l], tree[r]);
    }
  }
  int query(int curNode, int start, int end,
    int qx, int qy) {
    if(qx == start && qy == end)
      return tree[curNode];

    int l = curNode*2 + 1;
    int r = curNode*2 + 2;
    int mid = (start+end)/2;

    if(qy <= mid)
      return query(l, start, mid, qx, qy);
    else if(qx > mid)
      return query(r, mid+1, end, qx, qy);
    else
      return mergeNodes(
        query(l, start, mid, qx, mid),
        query(r, mid+1, end, mid+1, qy));
  }
};

int main() {
  int N, Q, T;
  scanf("%d", &T);

  for(int t = 1; t <= T; t++) {
    scanf("%d%d", &N, &Q);
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
      scanf("%d", &arr[i]);

    SegmentTree ss(arr);
    printf("Scenario #%d:\n", t);
    for(int i = 0; i < Q; i++) {
      int a, b;
      scanf("%d%d", &a, &b);

      printf("%d\n", ss.query(0, 0, N-1, a-1, b-1));
    }
  }
  return 0;
}
