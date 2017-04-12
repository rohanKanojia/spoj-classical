#include <cstdio>
#include <cmath>

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    double ans = (a*b*c) / (a*b + b*c + a*c + 2 * sqrt(a*b*c*(a+b+c)));
    printf("%0.6lf\n", ans);
  }
  return 0;
}
