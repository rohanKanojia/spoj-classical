#include <cstdio>
#include <vector>
using namespace std;

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N, listSum = 0;
    scanf("%lld", &N);

    vector<long long> list(N);
    for(long long i = 0; i < N; i++) {
      scanf("%lld", &list[i]);
      listSum += list[i];
    }
    printf("%lld\n", N - (listSum%N != 0));
  }
  return 0;
}
