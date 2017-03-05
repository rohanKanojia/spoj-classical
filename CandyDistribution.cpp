#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long N;
  while(true) {
    cin >> N;
    if(N == 0) 
      break;
    vector<long long> price(N), students(N);

    for(long long i = 0; i < N; i++)
      cin >> students[i];
    for(long long i = 0; i < N; i++)
      cin >> price[i];

    sort(students.rbegin(), students.rend());
    sort(price.begin(), price.end());

    long long ans = 0;
    for(long long i = 0; i < N; i++)
      ans += (students[i] * price[i]);
    cout << ans << endl;
  }
  return 0;
}
