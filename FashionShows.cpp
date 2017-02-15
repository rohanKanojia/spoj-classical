#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  long long T;
  cin >> T;
  while(T--) {
    long long N;
    vector<long long> men, women;
    cin >> N;
    for(long long i = 0; i < N; i++) {
      long long tmp;
      cin >> tmp;
      men.push_back(tmp);
    }

    for(long long i = 0; i < N; i++) {
      long long tmp;
      cin >> tmp;
      women.push_back(tmp);
    }

    std::sort(men.begin(), men.end());
    std::sort(women.begin(), women.end());

    long long ans = 0;
    for(long long i = 0; i < N; i++)
      ans += men[i]*women[i];
    cout << ans << endl;
  }
  return 0;
}
