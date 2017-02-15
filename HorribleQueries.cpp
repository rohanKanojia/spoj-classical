#include <iostream>
#include <vector>
using namespace std;

class BITree {
  vector<long long> BIT;
  void initializeBIT(long long N) {
    BIT.push_back(0); // dummy node
    for(long long i = 1; i <= N; i++)
      BIT.push_back(0);
  }
  long long getParent(long long index) { return index - (index&(-index)); }
  long long getNext(long long index) { return index + (index&(-index)); }
public:
  BITree(long long N)  { initializeBIT(N); }
  BITree(vector<long long>& arr) {
    initializeBIT(arr.size());
    for(long long i = 1; i <= arr.size(); i++)
      update(i, arr[i-1]); 
  }
  void update(long long index, long long val) {
    index = index + 1;

    while(index <= BIT.size()) {
      BIT[index] += val;
      index = getNext(index);
    }
  }
  long long query(long long index) {
    long long sum = 0;
    index = index + 1;
    while(index > 0) {
      sum += BIT[index];
      index = getParent(index);
    }
    return sum;
  }
  void printTree() {
    for(long long i = 0; i < BIT.size(); i++) 
      std::cout << BIT[i] << " ";
    std::cout << endl;
  }
};

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long N, C, ans;
    cin >> N >> C;
    BITree b1(N), b2(N);
    for(long long i = 0; i < C; i++) {
      long long qType, a, b, val;
      cin >> qType >> a >> b;
      if(qType == 0) {
        cin >> val;
        b1.update(a, val);
        b1.update(b+1, -val);
        b2.update(a, val *(a-1));
        b2.update(b+1, -val*b);
      }
      else {
        ans = b1.query(b)*b - b2.query(b) - b1.query(a-1)*(a-1) + b2.query(a-1);
        cout << ans << endl;
      }
    }
  }
}
