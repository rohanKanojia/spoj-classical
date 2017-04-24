#include <cstdio>
#include <algorithm>
using namespace std;

#define SIZE 20001
int BIT[SIZE], arr[SIZE];

class BinaryIndexedTree {
  long long size;
  long long getParent(long long index) { return index - (index & -index); }
  long long getNext(long long index)   { return index + (index & -index); }
public:
  BinaryIndexedTree(int sz=SIZE) : size(sz) { std::fill(BIT, BIT+sz, 0); }
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
  int T, N;
  scanf("%d", &T);

  while(T--) {
    scanf("%d", &N);
    BinaryIndexedTree bit;
    for(int i = 1; i <= N; i++)
      bit.update(i, 1);

    int packSize=N, L=1, s, e;
    for(int i = 1; i <= N; i++) {
      L = (L+i) % packSize;
      if(L == 0)
        L = packSize;

      s = 1, e = N;   // binary search to find out minimum s such that there are 
      while(s <= e) { // at least L 1's among first s elements
        int mid = (s+e)>>1;
        int midQ = bit.query(mid);
        if(midQ >= L)
          e = mid-1;
        else if(midQ < L)
          s = mid+1;
      }
      arr[s] = i;
      bit.update(s, -1); // card removed
      packSize--;
    }

    for(int i = 1; i <= N; i++)
      printf("%d ", arr[i]);
    printf("\n");
  }
  return 0;
}
