#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N, K;
    double start = 0.0f, end = 0.0f;
    scanf("%d%d", &N, &K);
    vector<double> radiuses(N);
    for(int i = 0; i < N; i++) {
      scanf("%lf", &radiuses[i]);
      end = std::max(end, (double)PI*radiuses[i]*radiuses[i]);
    }
    
    for(int i = 0; i < 100; i++) {
      double mid = (start+end)/2;

      int nPieces = 0;
      for(int j = 0; j < N; j++)
        nPieces += (radiuses[j] * radiuses[j] * PI)/mid;
      
      if(nPieces >= K+1)
        start = mid;
      else
        end = mid;
    }
    printf("%.4f\n", start);
  }
  return 0;
}
