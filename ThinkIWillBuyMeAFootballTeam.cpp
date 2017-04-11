#include <cstdio>
#include <vector>
using namespace std;

int main() {
  long long nCase = 1;
  while(true) {
    long long N, before = 0, after = 0;
    scanf("%lld", &N);
    if(N == 0) break;

    vector<long long> banks(N, 0);
    for(long long i = 0; i < N; i++) {
      for(long long j = 0; j < N; j++) {
        long long aTransaction;
        scanf("%lld", &aTransaction);
        banks[i] -= aTransaction;
        banks[j] += aTransaction;
        before += aTransaction;
      }
    }

    for(long long i = 0; i < N; i++)
      if(banks[i] > 0)
        after += banks[i];

    printf("%lld. %lld %lld\n", nCase++, before, after);
  }
  return 0;
}
