#include <cstdio>
#include <algorithm>
using namespace std;

class BinaryIndexedTree {
  int tree[30001];
  int getParent(int index)   { return index - (index & (-index)); }
  int getNext(int index)     { return index + (index & (-index)); } 
public:
  BinaryIndexedTree()  { std::fill(tree, tree + 30001, 0); }
  void update(int index, int val) {
    for(; index < 30001; index = getNext(index))
      tree[index] += val;
  }
  int query(int index) {
    int sum = 0;
    for(; index > 0; index = getParent(index)) 
      sum += tree[index];
    return sum;
  }
};
struct Query { int i, j, value, rank; };
Query queries[300001];
bool myComp(Query a, Query b) { return (a.value == b.value) ? (a.j  > b.j) : (a.value > b.value); }

int main() {
  int N, M;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &queries[i].value);
    queries[i].i = i+1;
    queries[i].j = -1;
  }
  scanf("%d", &M);
  int results[M];

  for(int i = 0; i < M; i++) {
    scanf("%d%d%d", &queries[i+N].i, &queries[i+N].j, &queries[i+N].value);
    queries[i+N].rank = i;
  }
  sort(queries, queries + M + N, myComp);

  BinaryIndexedTree bit;
  for(int i = 0; i < N+M; i++) {
    if(queries[i].j == -1)
      bit.update(queries[i].i, 1);
    else  
      results[queries[i].rank] = bit.query(queries[i].j) - bit.query(queries[i].i - 1);
  }

  for(int i = 0; i < M; i++) 
    printf("%d\n", results[i]);
  return 0;
}
