#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  long long T;
  scanf("%lld", &T);
  
  while(T--) {
    long long N;
    scanf("%lld", &N);

    string ss, mWord("manku");
    while(N > 0) {
      ss = mWord[(N-1)%5] + ss;
      N = (N-1)/5;
    }
    printf("%s\n", ss.c_str());
  }
  return 0;
}
