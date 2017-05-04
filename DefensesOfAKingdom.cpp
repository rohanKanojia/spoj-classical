#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 40004
int tx[SIZE], ty[SIZE];

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int W, H, N, idx = 2;
    scanf("%d%d", &W, &H);

    scanf("%d", &N);
    tx[0] = 0, ty[0] = 0;
    tx[1] = W+1, ty[1] = H+1;
    for(int i = 0; i < N; i++, idx++)
      scanf("%d%d", &tx[idx], &ty[idx]);

    std::sort(tx, tx+ idx);
    std::sort(ty, ty+ idx);

    // calculate empty spaces
    int maxX = 0, maxY = 0;
    for(int i = 1; i < idx; i++) {
      maxX = std::max(tx[i] - tx[i-1] - 1, maxX); // -1 because line covered by higher
      maxY = std::max(ty[i] - ty[i-1] - 1, maxY); // tower is included in it.
    }

    printf("%d\n", maxX * maxY);
  }
  return 0;
}
