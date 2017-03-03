#include <cstdio>
#include <string>
using namespace std;

#define SIZE 30000

typedef struct Node { int open, close; } Node;

class SegmentTree {
  Node tree[4*SIZE];
  int parents[SIZE], size;
  string elements;
  Node mergeNodes(Node a, Node b) {
    Node res;
    int change = std::min(a.open, b.close);
    res.open = a.open + b.open - change;
    res.close = a.close + b.close - change;
    return res;
  }
public:
  SegmentTree(string arr) : size(arr.length()) {
    elements = arr;
    buildTree(0, 0, size-1);
  }
  void buildTree(int curNode, int start, int end) {
    if(start == end) {
      tree[curNode].open = (elements[start] == ')' ? 0 : 1);
      tree[curNode].close = (elements[start] == ')' ? 1 : 0);
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
      return mergeNodes(query(l, start, mid, qx, qy), query(r, mid+1, end, mid+1, qy));
  }
  void update(int x) {
    int curNode = parents[x];
    Node prevVal = tree[curNode];
    tree[curNode].open = !(prevVal.open == 1);
    tree[curNode].close = !(prevVal.close == 1);

    curNode = (curNode-1)/2;
    while(curNode > 0) {
      tree[curNode] = mergeNodes(tree[2*curNode+1], tree[2*curNode+2]);
      curNode = (curNode-1)/2;
    }
    tree[0] = mergeNodes(tree[1], tree[2]);
  }
};

int main() {
  int N, Q, nCase = 1;
  while(scanf("%d", &N) == 1) {
    char str[SIZE];
    scanf("%s", str);
    string curStr(str);
    
    scanf("%d", &Q);
    SegmentTree ss(curStr);
    printf("Test %d:\n", nCase++);
    while(Q--) {
      int op;
      scanf("%d", &op);
      if(op == 0) {
        Node res = ss.query(0, 0, N-1, 0, N-1);
        printf("%s\n", (res.open == 0 && res.close == 0 ? "YES" : "NO"));
      }
      else
        ss.update(op-1);
    }
  }
  return 0;
}
