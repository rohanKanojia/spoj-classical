#include <iostream>
using namespace std;

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long n, m;
    cin >> n >> m;

    char ans;
    if(n <= m) 
      ans = (n%2 ? 'R' : 'L');
    else 
      ans = (m%2 ? 'D' : 'U');
    cout << ans << endl;
  }
  return 0;
}
