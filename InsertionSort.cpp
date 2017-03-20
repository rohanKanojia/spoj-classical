#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class BITree {
  vector<long long> BIT;
  void initializeBIT(long long N) {
    BIT.push_back(0);
    for(long long i = 1; i <= N; i++)
      BIT.push_back(0);
  }
  long long getParent(long long index) { return index - (index & (-index)); }
  long long getNext(long long index) { return index + (index & (-index)); }
public:
  BITree(long long N) { initializeBIT(N); }
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
};

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N;
    cin >> N;
    vector<long long> arr(N);
    for(long long i = 0; i < N; i++)
      cin >> arr[i];
    
    vector<long long> rank(arr);
    BITree bit(N);
    sort(arr.begin(), arr.end());
    for(int i = 0; i < N; i++) {
      int curRank = lower_bound(arr.begin(), arr.end(), rank[i]) - arr.begin();
      rank[i] = curRank + 1;
    }

    long long ans = 0;
    for(int i = N-1; i >= 0; i--) {
      long long x =  bit.query(rank[i] - 1);
      ans += x;
      bit.update(rank[i], 1);
    }
    cout << ans << endl;
  }
  return 0;
}
