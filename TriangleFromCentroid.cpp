#include <cstdio>
#include <cmath>

int main() {
  long long T;
  scanf("%lld", &T);

  while(T--) {
    double a, ga, gb, gc, area, HO, R, HG, b, c;
    scanf("%lf%lf%lf%lf", &a, &ga, &gb, &gc);
    area = a*ga*3/2;
    b = 2*area/(gb*3);
    c = 2*area/(gc*3);

    R = (a*b*c)/(4*area);
    HO = (9*R*R-a*a-b*b-c*c);
    if(HO < 0)
      HO = 0;
    HO = sqrt(HO);
    HG = 2*HO/3;
    printf("%.3lf %.3lf\n", area, HG);
  }
  return 0;
}
