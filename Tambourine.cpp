#include <cstdio>
#include <cmath>

int main() {
  while(1) {
    double r, N;
    scanf("%lf%lf", &r, &N);

    if(!r || !N) break;

    N = 2*N;
    double angle = ((N-2)*M_PI) / (2*N);
    printf("%.2lf\n", r/cos(angle));
  }
  return 0;
}
