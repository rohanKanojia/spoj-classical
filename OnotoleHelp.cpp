#include <cstdio>
using namespace std;

int main() {
  long long T, ans = 0;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);
    ans ^= N;
  }
  printf("%lld\n", ans);
}
