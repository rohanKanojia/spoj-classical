#include <cstdio>
using namespace std;

#define MOD 5000000
#define SIZE 100001

int bit[51][SIZE];
class BinaryIndexedTree {
  int getParent(int index)   { return index - (index & -index); }
  int getNext(int index)     { return index + (index & -index); }
public:
  void update(int K, int index, int val) {
    for(int i = index; i < SIZE; i = getNext(i)) {
      bit[K][i] += val;
      if(bit[K][i] >= MOD)
        bit[K][i] -= MOD;
    }
  }
  int query(int K, int index) {
    int ans = 0;
    for(int i = index; i > 0; i = getParent(i)) {
      ans += bit[K][i];
      if(ans >= MOD)
        ans -= MOD;
    }
    return ans;
  }
};

int main() {
  int N, K, curElem;
  scanf("%d%d", &N, &K);

  BinaryIndexedTree bit;
  for(int i = 0; i < N; i++) {
    scanf("%d", &curElem);

    for(int k = K; k > 1; k--) 
      bit.update(k, curElem+1, bit.query(k-1, curElem));
    bit.update(1, curElem+1, 1);
  }

  printf("%d\n", bit.query(K, SIZE-1));
  return 0;
}
