#include <cstdio>
#include <vector>
using namespace std;

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N, U, Q;
    scanf("%lld%lld", &N, &U);
    vector<long long> arr(N), diffArr(N+1, 0);

    for(long long i = 0; i < U; i++) {
      long long start, end, val;
      scanf("%lld%lld%lld", &start, &end, &val);
      diffArr[start] += val;
      diffArr[end+1] -= val;
    }

    long long sum = 0;
    for(long long i = 0; i < N; i++) {
      sum += diffArr[i];
      arr[i] = sum;
    }

    scanf("%lld", &Q);
    for(long long i = 0; i < Q; i++) {
      long long index;
      scanf("%lld", &index);
      printf("%lld\n", arr[index]);
    }
  }
  return 0;
}
