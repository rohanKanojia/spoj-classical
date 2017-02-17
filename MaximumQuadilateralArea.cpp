#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    double a, b, c, d, s, ans;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    s = (a+b+c+d)/2;
    ans = sqrt((s-a)*(s-b)*(s-c)*(s-d));
    printf("%0.2lf\n", ans);
  }
  return 0;
}
