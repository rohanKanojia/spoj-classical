#include <cstdio>
#include <vector>
using namespace std;

const long long modVal = 1000000007;

long long fibSum(long long x);
void multiply(vector<vector<long long> >& a, vector<vector<long long> >& b); 
long long fibonacci(long long x);

int main() {
  long long T;
  scanf("%lld", &T);
  while(T--) {
    long long a, b;
    scanf("%lld%lld", &a, &b);

    long long ans = (fibSum(b) - fibSum(a-1)) % modVal;
    if(ans < 0)
      ans += modVal;
    ans %= modVal;

    printf("%lld\n", ans);
  }
  return 0;
}

long long fibSum(long long x) {
  return fibonacci(x+2) - 1;
}

long long fibonacci(long long n) {
  long long curVal = 1;
  vector<vector<long long> > ans = { {1,0}, {0,1} }; // identity matrix
  vector<vector<long long> > M = { {0,1}, {1,1} };
  
  while(n > 0) {
    if(n & curVal) {
      n -= curVal;
      multiply(ans, M);
    }
    curVal <<= 1;
    multiply(M, M);
  }
  return ans[0][1] % modVal;
}

void multiply(vector<vector<long long> >& a, vector<vector<long long> >& b) {
  vector<vector<long long> > res = { {0, 0}, {0, 0} };

  for(long long i = 0; i < res.size(); i++) {
    for(long long j = 0; j < res[i].size(); j++) {
      for(long long k = 0; k < res[i].size(); k++)
        res[i][j] += ((a[i][k] * (b[k][j] % modVal))% modVal);
    }
  }

  a = res; // copy result back in a
}
