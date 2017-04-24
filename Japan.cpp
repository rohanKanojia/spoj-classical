#include <cstdio>
#include <algorithm>
using namespace std;

#define SIZE 1000009
struct Road { int u, v; };
bool myComp(const Road a, const Road b) { return (a.u == b.u ? (a.v < b.v) : (a.u < b.u)); }
Road roads[SIZE];
long long BIT[10000];

class BinaryIndexedTree {
  long long size;
  long long getParent(long long index) { return index - (index & -index); }
  long long getNext(long long index)   { return index + (index & -index); }
public:
  BinaryIndexedTree(int sz) : size(sz) { std::fill(BIT, BIT+sz+1, 0); }
  void update(long long index, long long value) {
    for(; index <= size; index = getNext(index))
      BIT[index] += value;
  }
  long long query(long long index) {
    long long sum = 0;
    for(; index > 0; index = getParent(index))
      sum += BIT[index];
    return sum;
  }
};

int main() {
  long long T, nCase = 1;
  scanf("%lld", &T);

  while(T--) {
    long long N, M, K, ans = 0;
    scanf("%lld%lld%lld", &N, &M, &K);

    for(long long i = 0; i < K; i++)
      scanf("%d%d", &roads[i].u, &roads[i].v);

    std::sort(roads, roads + K, myComp);
    BinaryIndexedTree bit(M);
    for(long long i = 0; i < K; i++) {
      bit.update(roads[i].v, 1);
      ans += (bit.query(M) - bit.query(roads[i].v)); 
    }
    printf("Test case %lld: %lld\n", nCase++, ans);
  }
  return 0;
}
