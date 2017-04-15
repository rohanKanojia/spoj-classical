#include <cstdio>
#include <cmath>
#include <algorithm>

int main() {
  int R, C, nRed, nBrown;
  scanf("%d%d", &nRed, &nBrown);
  R = ((nRed+4) + sqrt((nRed+4)*(nRed+4) - 16*(nRed+nBrown)))/4;
  C = (nRed+nBrown)/R;
  printf("%d %d\n", std::max(R, C), std::min(R, C));
  return 0;
}
