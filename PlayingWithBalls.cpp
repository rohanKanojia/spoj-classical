#include <cstdio>
using namespace std;

int main() {
  int T, W, B;
  scanf("%d", &T);

  while(T--) {
    scanf("%d%d", &W, &B);
    double ans = 0;
    if(B&1)
      ans = 1;
    printf("%.6lf\n", ans);
  }
  return 0;
}
