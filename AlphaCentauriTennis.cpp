#include <cstdio>
#include <cstring>

char aSequence[50001];

int main() {
  int T, N;
  scanf("%d", &T);

  while(T--) {
    scanf("%d %s", &N, aSequence);
    printf("%c\n", aSequence[strlen(aSequence)-1]);
  }
  return 0;
}
