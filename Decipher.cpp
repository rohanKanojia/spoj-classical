#include <cstdio>
#include <cmath>

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);

    /*
     * Since we need to find roots distance: P^2+Q^2+R^2,
     * Remember the relation between coefficients and roots of a cubic polynomial:
     * a*x^3 + b*x&2 + c*x + d = 0
     * P + Q + R = -b/a
     * P*Q + Q*R + R*P = c/a
     */

    printf("%lld\n", a*a-2*b);
  }
  return 0;
}
