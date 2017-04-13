#include <cstdio>
#include <cmath>

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    double volume, a, ans;
    scanf("%lf", &volume);
    a = pow(4*volume, 1/3.);
    ans = (3*a*a*sqrt(3))/2;
    printf("%.10lf\n", ans);
  }
  return 0;
}
