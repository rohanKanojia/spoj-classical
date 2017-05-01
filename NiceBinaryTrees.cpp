#include <cstdio>
#include <algorithm>
using namespace std;

#define SZ 1010
int index;
void getLength(char aStr[], int level, int& nDepth) {
  nDepth = std::max(nDepth, level);
  index++;
  if(aStr[index] == 'l')
    return;
  if(aStr[index] == 'n') {
    getLength(aStr, level+1, nDepth);
    getLength(aStr, level+1, nDepth);
  }
}

int main() {
  int T;
  char aStr[SZ];
  scanf("%d", &T);

  while(T--) {
    int nDepth = 0;
    scanf("%s", aStr);
    
    index = -1;
    getLength(aStr, 0, nDepth);
    printf("%d\n", nDepth);
  }
  return 0;
}
