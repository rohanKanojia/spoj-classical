#include <cstdio>
#include <algorithm>

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(c > a && c > b)
      printf("NO\n");
    else if(c % (std::__gcd(a, b)) == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
