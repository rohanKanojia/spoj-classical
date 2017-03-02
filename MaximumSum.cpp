#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 100000
struct Node { long long maxVal, secondMax; };

class SegmentTree {
  Node tree[4*SIZE];
  long long parents[SIZE];
  long long size;
  vector<long long> elements;
  Node mergeNodes(Node a, Node b) {
    Node res;
    vector<long long> tmpV { a.maxVal, a.secondMax, b.maxVal, b.secondMax };
    std::sort(tmpV.begin(), tmpV.end(), std::greater<int>());
    res.maxVal = tmpV[0];
    res.secondMax = tmpV[1];

    return res;
  }
public:
  SegmentTree(vector<long long> arr) : size(arr.size()) {
    elements = arr;
    buildTree(0, 0, size-1);
  }
  void buildTree(long long curNode, long long start, long long end) {
    if(start == end) {
      tree[curNode].maxVal = elements[start];
      tree[curNode].secondMax = 0;
      parents[start] = curNode;
    }
    else {
      long long l = curNode * 2 + 1;
      long long r = curNode * 2 + 2;

      long long mid = (start + end)/2;
      buildTree(l, start, mid);
      buildTree(r, mid+1, end);

      tree[curNode] = mergeNodes(tree[l], tree[r]);
    }
  }
  Node query(long long curNode, long long start, long long end, long long qx, long long qy) {
    if(qx == start && qy == end)
      return tree[curNode];

    long long l = curNode*2 + 1;
    long long r = curNode*2 + 2;
    long long mid = (start+end)/2;

    if(qy <= mid)
      return query(l, start, mid, qx, qy);
    else if(qx > mid)
      return query(r, mid+1, end, qx, qy);
    else
      return mergeNodes(query(l, start, mid, qx, mid), query(r, mid+1, end, mid+1, qy));
  }
  void update(long long x, long long val) {
    long long curNode = parents[x];
    tree[curNode].maxVal = val;
    tree[curNode].secondMax = 0;

    curNode = (curNode-1)/2;
    while(curNode > 0) {
      tree[curNode] = mergeNodes(tree[2*curNode+1], tree[2*curNode+2]);
      curNode = (curNode-1)/2;
    }
    tree[0] = mergeNodes(tree[1], tree[2]);
  }
};

int main() {
  long long N, Q;
  cin >> N;
  vector<long long> arr(N);
  for(long long i = 0; i < N; i++)
    cin >> arr[i];
  cin >> Q;

  SegmentTree ss(arr);
  for(long long i = 0; i < Q; i++) {
    char op;
    long long x, y;
    cin >> op >> x >> y;
    if(op == 'Q') {
      Node res = ss.query(0, 0, N-1, x-1, y-1);
      cout << res.maxVal + res.secondMax << endl;
    }
    else 
      ss.update(x-1, y);
  }
  return 0;
}
