#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 100000
#define LOG2_MAXN 18
const long long INF = INT_MAX;

class SegmentTree {
  long long c[MAX_N+1], int_min[1<<(LOG2_MAXN)], int_max[1<<(LOG2_MAXN)];
  long long int_best[1<<(LOG2_MAXN)];
  long long size;
public:
  SegmentTree(long long arr[], long long N) {
    c[0] = 0;
    for(long long i = 0; i < N; i++)
      c[i+1] = c[i] + arr[i];
    size = N;
    buildTree(0, 0, N);
  }
  void buildTree(long long curNode, long long start, long long end){
    if(start == end){
        if(start!=0){
             int_min[curNode] = c[start-1];
             int_max[curNode] = c[start];
             int_best[curNode] = c[start]-c[start-1];
        }else{
             int_min[curNode] = 0;
             int_max[curNode] = 0;
             int_best[curNode] = 0;
        }
    }else{
        long long mid = (start+end)>>1;
        buildTree(2*curNode+1, start, mid);
        buildTree(2*curNode+2, mid+1, end);
        int_min[curNode] = min(int_min[2*curNode+1],int_min[2*curNode+2]);
        int_max[curNode] = max(int_max[2*curNode+1],int_max[2*curNode+2]);
        int_best[curNode] = max(int_max[2*curNode+2]-int_min[2*curNode+1],
                         max(int_best[2*curNode+1],int_best[2*curNode+2]));
    }
  }


  long long rangeQuery(long long start, long long end) {
    long long minPrefix = INF;
    return treeQuery(0, 0, size, start, end, minPrefix);
  }
  long long treeQuery(long long curNode, long long lo, long long hi, 
    long long qs, long long qe, long long& minPrefix) {
    
    if(qs <= lo && hi <= qe) {
      long long ret = int_best[curNode];
      if(minPrefix != INF)
        ret = std::max(ret, int_max[curNode]-minPrefix);
      minPrefix = std::min(minPrefix, int_min[curNode]);
      return ret;
    }
    else {
      long long mid = (lo + hi)>>1;
      if(mid < qs) treeQuery(2*curNode+2, mid+1, hi, qs, qe, minPrefix);
      else if(mid >= qe) treeQuery(2*curNode+1, lo, mid, qs, qe, minPrefix);
      else {
        long long val1 = treeQuery(2*curNode+1, lo, mid, qs, qe, minPrefix);
        long long val2 = treeQuery(2*curNode+2, mid+1, hi, qs, qe, minPrefix);

        return std::max(val1, val2);
      }
    }
  }
};

int main() {
  long long N, Q;
  scanf("%lld", &N);
  long long *arr = new long long[N];
  for(long long i = 0; i < N; i++)
    scanf("%lld", &arr[i]);

  SegmentTree ss(arr, N);
  scanf("%lld", &Q);
  for(long long i = 0; i < Q; i++) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", ss.rangeQuery(l, r));
  }
  return 0;
}
