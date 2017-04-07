#include <cstdio>
#include <vector>

#define SIZE 100001
char a[SIZE], b[SIZE];

int main() {
  int N, i, j;
  scanf("%d%s", &N, a);

  for(i = 0; i < 2*N; i += 2) {
    std::vector<bool> bFirstRow(4, false);
    bFirstRow[a[i]-'A'] = bFirstRow[a[i+1]-'A'] = true;

    for(j = 0; j < 4 && bFirstRow[j]; j++);
    bFirstRow[j] = true;
    b[i] = j + 'A';

    for(j = 0; j < 4 && bFirstRow[j]; j++);
    bFirstRow[j] = true;
    b[i+1] = j + 'A';

    if(i > 0 && b[i-1] == b[i]) 
      std::swap(b[i], b[i+1]);
  }
  b[i] = '\0';
  printf("%s\n", b);
  return 0;
}
