#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    char aStr[10];
    int N, ans = -1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      int curDigit;
      scanf("%s", aStr);
      curDigit = (aStr[0] == 'l' ? 1 : 0);

      if(ans == -1)
        ans = curDigit;
      else
        ans ^= curDigit;
    }
    printf("%s\n", ans == 1 ? "lxh" : "hhb");
  }
  return 0;
}
