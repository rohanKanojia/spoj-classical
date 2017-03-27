#include <cmath>
#include <cstdio>
using namespace std;

double calcCos(double a, double b, double c) {
  return (a*a + b*b - c*c) / (2.0*a*b);
}


double calcArea(double a, double b, double c) {
  double s = (a + b + c)/2.;
  return sqrt(s * (s-a) * (s-b) * (s-c));
}

double calcVolume(double u, double v, double w, double U, double V, double W) {
  return sqrt(
    4*u*u*v*v*w*w- u*u*(v*v+w*w - U*U)*(v*v+w*w-U*U) - v*v*(w*w+u*u - V*V)*(w*w+u*u-V*V) 
    - w*w*(u*u + v*v - W*W)*(u*u+v*v-W*W) + (v*v +w*w - U*U)*(w*w+u*u- V*V)*(u*u+v*v - W*W)
  )/12;
}

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    double u, v, w, U, V, W;
    scanf("%lf%lf%lf%lf%lf%lf", &u, &v, &w, &W, &V, &U);

    double volume = calcVolume(u, v, w, U, V, W); 
    double a1 = calcArea(u, v, W);
    double a2 = calcArea(v, w, U);
    double a3 = calcArea(u, V, w);
    double a4 = calcArea(W, V, U);

    double ans = (3 * volume) / (a1 + a2 + a3 + a4);
    printf("%.4f\n", ans);
  }
  return 0;
}
