#include <iostream>
#include <string>
using namespace std;

long long minStableReplacements(string& ss);

int main() {
  long long nCase = 1;
  while(1) {
    string ss;
    cin >> ss;

    if(ss[0] == '-') break;

    cout << nCase++ << ". " << minStableReplacements(ss) << endl;
  
  }
  return 0;
}

long long minStableReplacements(string& ss) {
  long long nOpen = 0, nClose = 0, ans = 0;

  for(long long i = 0; i < ss.length(); i++) {
    if(ss[i] == '{')
      nOpen++;
    else if(ss[i] == '}') {
      if(nOpen > 0)
        nOpen--;
      else
        nClose++;
    }
  }

  if(nOpen >= 2) {
    ans += nOpen/2;
    nOpen = nOpen%2;
  }
  if(nClose >= 2) {
    ans += nClose/2;
    nClose = nClose%2;
  }

  return ans + nOpen + nClose;
}
