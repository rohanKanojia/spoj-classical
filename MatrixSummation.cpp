#include <cstdio>
#include <vector>
using namespace std;

class BITree2D {
  vector<vector<long long> > BIT;
  int N;
  void initializeBIT(long long N) {
    for(long long i = 0; i < N+1; i++)
      BIT.push_back(vector<long long>(N+1, 0));
  }
  long long getParent(long long index) { return index - (index & -index); }
  long long getNext(long long index)   { return index + (index & -index); }
public:
  BITree2D(long long n) : N(n+1)       { initializeBIT(N); }
  void update(long long r, long long c, long long val) {
    val = val - rangeQuery(r, c, r, c);
    for(long long i = r; i <= N; i = getNext(i)) 
      for(long long j = c; j <= N; j = getNext(j)) {
        BIT[i][j] += val;
      }
  }
  long long query(long long r, long long c) { 
    int sum = 0;

    for(long long i = r; i > 0; i = getParent(i)) 
      for(long long j = c; j > 0; j = getParent(j)) {
        sum += BIT[i][j];
      }
    return sum;
  }
  long long rangeQuery(long long r1, long long c1,
    long long r2, long long c2) {
    
    return query(r2, c2) - query(r2, c1-1) -
      query(r1-1, c2) + query(r1-1, c1-1);
  }
};

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long N;
    scanf("%lld", &N);
    BITree2D bit(N);

    while(true) {
      char operation[10];
      scanf("%s", operation);
      if(operation[1] == 'E') {
          long long r, c, val;
          scanf("%lld%lld%lld", &r, &c, &val);
          bit.update(r+1, c+1, val);
      }
      else if(operation[1] == 'U') {
          long long r1, c1, r2, c2;
          scanf("%lld%lld%lld%lld", &r1, &c1, &r2, &c2);
          printf("%lld\n", bit.rangeQuery(r1+1, c1+1, r2+1, c2+1));
      }
      else break;
    }
  }
  return 0;
}
