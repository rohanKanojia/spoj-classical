#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  long long N;

  while(1) {
    cin >> N;
    if(N == 0) break;

    vector<long long> invPermutation(N);
    vector<long long> arr;
    map<long long, long long> positionOf;

    for(long long j = 0; j < N; j++) {
      long long tmp;
      cin >> tmp;
      positionOf[tmp] = j;
      arr.push_back(tmp);
    }
    for(long long i = 1; i <= N; i++) {
      invPermutation[i-1] = positionOf[i]+1;
    }

    cout << ((arr == invPermutation) ? "ambiguous" : "not ambiguous") << endl;
  }
  return 0;
}
