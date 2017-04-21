#include <cstdio>
#include <set>
using namespace std;

int main() {
  long long N, nReciepts, aReciept;
  scanf("%lld", &N);

  multiset<long long> mm;
  long long sum = 0;
  for(long long i = 0; i < N; i++) {
    scanf("%lld", &nReciepts);
    for(long long j = 0; j < nReciepts; j++) {
      scanf("%lld", &aReciept);
      mm.insert(aReciept);
    }
    multiset<long long>::iterator start = mm.begin(), end = mm.end();
    end--;
    sum += (*end - *start);

    mm.erase(start);
    mm.erase(end);
  }
  printf("%lld\n", sum);
  return 0;
}
