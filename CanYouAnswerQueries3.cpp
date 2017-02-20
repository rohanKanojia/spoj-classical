#include <cstdio>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define SIZE 50000
struct Node {
  long long sum, maxSum, prefixSum, suffixSum;
};

class SegmentTree {
  Node tree[4*SIZE];
  long long parents[SIZE];
  vector<long long> elements;
  long long size;
  Node mergeNodes(Node a, Node b) {
    Node res;
    res.sum = a.sum + b.sum;
    res.maxSum = std::max(std::max(a.maxSum, b.maxSum), (a.suffixSum + b.prefixSum));
    res.prefixSum = std::max(a.prefixSum, a.sum + b.prefixSum);
    res.suffixSum = std::max(b.suffixSum, b.sum + a.suffixSum);
    return res;
  }
public:
  SegmentTree(vector<long long> arr) : size(arr.size()) {
    elements = arr;
    buildTree(0, 0, size-1); 
  }
  void buildTree(long long curNode, long long start, long long end) {
    if(start == end) {
      tree[curNode].prefixSum = tree[curNode].suffixSum = tree[curNode].sum = tree[curNode].maxSum = elements[start];
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
    if(qx == start && end == qy) {
      return tree[curNode];
    }

    long long l = curNode * 2 + 1;
    long long r = curNode * 2 + 2;
    long long mid = (start+end)/2;

    if(qy <= mid) 
      return query(l, start, mid, qx, qy);
    else if(qx > mid)
      return query(r, mid+1, end, qx, qy);
    else {
      return mergeNodes(query(l, start, mid, qx, mid), query(r, mid+1, end, mid+1, qy));
    }
  }
  void update(long long x, long long val) {
    long long curNode = parents[x];

    tree[curNode].prefixSum = tree[curNode].suffixSum = tree[curNode].sum = tree[curNode].maxSum = val;

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
  scanf("%lld", &N);
  vector<long long> arr(N);
  for(long long i = 0; i < N; i++)
    scanf("%lld", &arr[i]);
  scanf("%lld", &Q);

  SegmentTree ss(arr);
  for(long long i = 0; i < Q; i++) {
    long long op, a, b;
    scanf("%lld%lld%lld", &op, &a, &b);
    if(op == 1) 
      printf("%lld\n", ss.query(0, 0, N-1, a-1, b-1).maxSum);
    else 
      ss.update(a-1, b);
  }
  return 0;
}
