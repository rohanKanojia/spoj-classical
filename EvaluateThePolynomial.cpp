#include <iostream>
#include <vector>
using namespace std;

long long horner(vector<long long>& poly, long long x) {
  long long sum = poly[0];

  for(long long i = 1; i < poly.size(); i++) 
    sum = sum*x + poly[i];

  return sum;
}

int main() {
  long long nCase = 1;
  while(true) {
    long long N, Q;
    cin >> N;
    if(N == -1) break;
    vector<long long> poly(N+1);
    for(int i = 0; i <= N; i++)
      cin >> poly[i];

    cin >> Q;
    cout << "Case " << nCase++ << ":\n";
    for(int i = 0; i < Q; i++) {
      long long x;
      cin >> x;
      cout << horner(poly, x) << endl;
    }
  }
  return 0;
}
