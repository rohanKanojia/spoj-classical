#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 100000
struct Node { int best, left, right; };

class SegmentTree {
  Node tree[4*SIZE];
  int parents[SIZE];
  vector<int> elements;
  int size;
  Node mergeNodes(Node a, Node b, int mid, int start, int end) {
    Node res;
    if(elements[mid] == elements[mid+1]) {
      res.left  = a.left + b.left * (elements[start] == elements[mid]);
      res.right = b.right + a.right * (elements[end] == elements[mid+1]);
      int temp  = a.right + b.left;
      res.best  = std::max(temp, std::max(a.best, b.best)); 
    }
    else {
      res.left  = a.left;
      res.right = b.right;
      res.best  = std::max(a.best, b.best); 
    }
    return res;
  }
public:
  SegmentTree(vector<int> arr) : size(arr.size()) {
    elements = arr;
    buildTree(0, 0, size-1);
  }
  void buildTree(int curNode, int start, int end) {
    if(start == end) {
      tree[curNode].best = tree[curNode].left 
        = tree[curNode].right = 1;
      parents[start] = curNode;
    }
    else {
      int l = curNode * 2 + 1;
      int r = curNode * 2 + 2;

      int mid = (start + end)/2;
      buildTree(l, start, mid);
      buildTree(r, mid+1, end);

      tree[curNode] = mergeNodes(tree[l], tree[r], mid, start, end);
    }
  }
  Node query(int curNode, int start, int end, 
    int qx, int qy) {
    if(qx == start && qy == end)
      return tree[curNode];

    int l = curNode * 2 + 1;
    int r = curNode * 2 + 2;
    int mid = (start+end)/2;

    if(qy <= mid)
      return query(l, start, mid, qx, qy);
    else if(qx > mid)
      return query(r, mid+1, end, qx, qy);
    else
      return mergeNodes(
        query(l, start, mid, qx, mid),
        query(r, mid+1, end, mid+1, qy), mid, start, end);
  }
};

int main() {
  int N, Q;
  while(true) {
    scanf("%d", &N);
    if(N == 0) break;
    scanf("%d", &Q);
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
      scanf("%d", &arr[i]);
    SegmentTree ss(arr);

    while(Q--) {
      int a, b;
      scanf("%d%d", &a, &b);

      printf("%d\n", ss.query(0, 0, N-1, a-1, b-1).best);
    }
  }
  return 0;
}
