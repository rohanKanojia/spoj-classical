#include <cstdio>
#include <cmath>

int main() {
  int N, aQuater = 0, ThreeQuater = 0, half = 0, ans = 0;
  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    int a, b;
    scanf("%d/%d", &a, &b);
    if(a == 3 && b == 4)
      ThreeQuater++;
    else if(a == 1 && b == 2)
      half++;
    else
      aQuater++;
  }

  ans += ThreeQuater;
  aQuater = aQuater - ThreeQuater;

  ans += half/2;

  if(half%2) {
    ans++;
    aQuater -= 2;
  }

  if(aQuater > 0) {
    ans += aQuater/4;
    if(aQuater%4) {
      ans++;
    }
  }
  printf("%d\n", ans+1);
  return 0;
}
