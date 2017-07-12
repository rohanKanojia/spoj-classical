#include <cstdio>
#include <unistd.h>
#include <vector>
#include <algorithm>

#define SIZE 10001

struct Node {
  int sum, maxSum, prefixSum, suffixSum;
  Node() : sum(0), maxSum(0), prefixSum(0), suffixSum(0) { }
  Node(int sum, int maxSum, int prefixSum, int suffixSum) {
    this->sum        = sum;
    this->maxSum     = maxSum;
    this->prefixSum  = prefixSum;
    this->suffixSum  = suffixSum;
  }
  static Node nullNode;
};
Node Node::nullNode;


class SegmentTree {
  Node tree[4*SIZE];
  int parents[SIZE], size;
  std::vector<int> elements;
  Node mergeNodes(Node a, Node b) {
    Node res;
    res.sum = a.sum + b.sum;
    res.maxSum = std::max(
                   std::max(a.maxSum, b.maxSum),
                   a.suffixSum + b.prefixSum
                 );
    res.prefixSum = std::max(a.prefixSum, a.sum + b.prefixSum);
    res.suffixSum = std::max(b.suffixSum, b.sum + a.suffixSum);
    return res;
  }
public:
  SegmentTree(std::vector<int> arr) : size(arr.size()) {
    elements = arr;
    buildTree(0, 0, size-1);
  }
  void buildTree(int curNode, int start, int end) {
    if(start == end) {
      tree[curNode].prefixSum = tree[curNode].suffixSum = tree[curNode].sum = tree[curNode].maxSum = elements[start];
      parents[start] = curNode;
    }
    else {
      int l = curNode * 2 + 1;
      int r = curNode * 2 + 2;

      int mid = (start + end)/2;
      buildTree(l, start, mid);
      buildTree(r, mid+1, end);

      tree[curNode] = mergeNodes(tree[l], tree[r]);
    }
  }
  Node query(int curNode, int start, int end, int qx, int qy) {
    if(qx > qy)                    return Node::nullNode;
    if(qx == start && end == qy)   return tree[curNode];

    int l = curNode*2 + 1;
    int r = curNode*2 + 2;
    int mid = (start+end)/2;

    if(qy <= mid)
      return query(l, start, mid, qx, qy);
    else if(qx > mid)
      return query(r, mid+1, end, qx, qy);
    else
      return mergeNodes(query(l, start, mid, qx, mid), query(r, mid+1, end, mid+1, qy));
  }
};

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N, Q;
    scanf("%d", &N);

    std::vector<int> aList(N);
    for(int i = 0; i < N; i++)
      scanf("%d", &aList[i]);

    SegmentTree aSegTree(aList);
    
    int ans;
    scanf("%d", &Q);
    while(Q--) {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      x1--, y1--, x2--, y2--;

      if(y1 < x2) { /* disjoint */
        ans = aSegTree.query(0, 0, N-1, x1, y1).suffixSum +
              aSegTree.query(0, 0, N-1, y1+1, x2-1).sum   +
              aSegTree.query(0, 0, N-1, x2, y2).prefixSum;
      }
      else {        /* joint   */
        ans = std::max(
                aSegTree.query(0, 0, N-1, x2, y1).maxSum,
                std::max(
                  aSegTree.query(0, 0, N-1, x1, x2-1).suffixSum + aSegTree.query(0, 0, N-1, x2, y2).prefixSum,
                  aSegTree.query(0, 0, N-1, x1, y1).suffixSum + aSegTree.query(0, 0, N-1, y1+1, y2).prefixSum
                )
              );
      }
      
      printf("%d\n", ans);
    }
  }
  return 0;
}
