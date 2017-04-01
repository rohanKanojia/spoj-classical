#include <cstdio>
#include <cstring>

#define SIZE 501
char S[SIZE], T[SIZE];

int main() {
  while(true) {
    scanf("%s%s", S, T);
    if(S[0] == '*' && T[0] == '*') break;

    int ans = 0, len = strlen(S);
    for(int i = 0; i < len; i++) {
      if(S[i] != T[i]) {
        ans++;
        while(i < len && S[i] != T[i]) i++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
