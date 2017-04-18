#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    double N;
    scanf("%lf", &N);
    printf("%.8lf\n", N/(N+1));
  }
  return 0;
}
