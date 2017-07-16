#include <cstdio>
#include <cmath>

int main() {
  int T;
  scanf("%d", &T);

  for(int t = 1; t <= T; t++) {
    int p0, p1, nT, p;
    scanf("%d%d%d%d", &p0, &p1, &nT, &p);

    // Find rate using first order reaction:
    double rate = (log(p) - log(p0)) / (log(p1) - log(p0));
    printf("Scenario #%d: %.2lf\n", t, rate * nT);
  }
  return 0;
}
