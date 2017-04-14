#include <cstdio>
#include <cmath>

#define PI (2*acos(0.0))
#define G 9.806

int main() {
  int T, nCase = 1;
  scanf("%d", &T);

  while(T--) {
    int d, v;
    scanf("%d%d", &d, &v);
    double sineVal = (d*G)/(v*v);
    if(sineVal <= 1) {
      double ans = (asin(sineVal)*180.0) / PI;
      printf("Scenario #%d: %.2f\n", nCase++, ans/2);
    }
    else
      printf("Scenario #%d: -1\n", nCase++);
  }
  return 0;
}
