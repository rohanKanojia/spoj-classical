#include <cstdio>
#include <map>
using namespace std;

int main() {
  int N, nPos, nGroups = 0;
  scanf("%d", &N);
  map<int, int> line;

  while(N--) {
    scanf("%d", &nPos);
    line[nPos]++;

    if(line[nPos-1] == 0 && line[nPos+1] == 0)
      nGroups++;
    else if(line[nPos-1] == 1 && line[nPos+1] == 1)
      nGroups--;
    printf("%d\n", nGroups);
  }
  printf("Justice\n");
  return 0;
}
