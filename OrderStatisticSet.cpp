#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 200001
char C[SIZE];
int input[SIZE];
typedef struct Elem { int value, c; } Elem;
Elem A[SIZE], B[SIZE];
bool myComp(Elem a, Elem b) { return a.value < b.value; }
int binarySearch(int target, int N) {
  int start = 1, end = N;
  while(start <= end) {
    int mid = (start+end)>>1;
    if(A[mid].value >= target)
      end = mid-1;
    else
      start = mid+1;
  }
  return start;
}

class BinaryIndexedTree {
  int BIT[SIZE+1];
  int getParent(int index) { return index - (index & (-index)); }
  int getNext(int index)   { return index + (index & (-index)); }
public:
  BinaryIndexedTree() { std::fill(BIT, BIT+SIZE, 0); }
  void update(int index, int val) {
    for(;index <= SIZE; index = getNext(index)) 
      BIT[index] += val;
  }
  int query(int index) {
    int res = 0;
    
    for(;index > 0; index = getParent(index)) 
      res += BIT[index];
    return res;
  }
};

int main() {
  int N, bI = 0, aI = 0, y;
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> C[i] >>input[i];
    if(C[i] == 'I')
      B[++bI].value = input[i];
  }
  std::sort(B+1, B+bI+1, myComp);

  for(int i = 1; i <= bI; i++) {
    if(B[i-1].value != B[i].value) {
      A[++aI].value = B[i].value;
      A[aI].c = 0;
    }
  }

  BinaryIndexedTree aTree;
  for(int i = 1; i <= N; i++) {
    switch(C[i]) {
      case 'I':
        y = binarySearch(input[i], aI);
        A[y].c++;
        if(A[y].c == 1)
          aTree.update(y, 1);
        break;
      case 'D':
        y = binarySearch(input[i], aI);
        if(A[y].c > 0 && A[y].value == input[i]) {
          aTree.update(y, -1);
          A[y].c = 0;
        }
        break;
      case 'C':
        y = binarySearch(input[i], aI);
        cout << aTree.query(y-1) << endl;
        break;
      case 'K':
        int start = 1, end = aI;
        while(start <= end) {
          int mid = (start+end)>>1;
          if(aTree.query(mid) >= input[i])
            end = mid-1;
          else
            start = mid+1;
        }
        if(start > aI)
          cout << "invalid\n";
        else
          cout << A[start].value << endl;
        break;
    }
  }
  return 0;
}
