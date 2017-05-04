#include <cstdio>
#include <cstring>

int main() {
  char rounds[200];
  
  scanf("%s", rounds);

  int N = strlen(rounds), nL = 0, nD = 0;

  for(int i = 1; i <= N; i++) {
    if(rounds[i%N] == '0' && rounds[(i-1)%N] == '0')
      nL++;
    if(rounds[i%N] == '0' && rounds[(i-1)%N] == '1')
      nD++;
  }

  if(nL == N || nL == nD)
    printf("EQUAL\n");
  else if(nL > nD)
    printf("SHOOT\n");
  else if(nL < nD)
    printf("ROTATE\n");

  return 0;
}
