#include <cstdio>
#include <climits>
#include <map>
#include <vector>
using namespace std;

char arr[1000][1000];
int bestR, bestC, bestDepth;
bool isVisited[1000][1000];
bool isValidCoord(int i, int j, int ROWS, int COLS) {
  return i>=0 && i < ROWS && j >=0 && j < COLS;
}

int dfs(int i, int j, int ROWS, int COLS, int depth) {
  if(bestDepth < depth) {
    bestDepth = depth;
    bestR = i, bestC = j;
  }
  int rowOffsets[4] = {-1, 0, 1, 0};
  int colOffsets[4] = {0, -1, 0, 1};

  isVisited[i][j] = true;
  int curR, curC, maxVal = 0;
  for(int index = 0; index < 4; index++) {
    curR = rowOffsets[index]+i, curC = colOffsets[index]+j;
    if(isValidCoord(curR, curC, ROWS, COLS))
      if(arr[curR][curC] == '.' && !isVisited[curR][curC])
        maxVal = std::max(maxVal, dfs(curR, curC, ROWS, COLS, depth+1));
  }
  return 1+maxVal;
}

void resetIsVisited(int N, int M) {
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      isVisited[i][j] = false;
}

int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int N, M;
    scanf("%d%d", &M, &N);
    for(int i = 0; i < N; i++)
      scanf("%s", arr[i]);

    resetIsVisited(N, M);
    int ans = -1, i, j;
    for(i = 0; i < N; i++) {
      for(j = 0; j < M; j++) {
        if(arr[i][j] == '.')
          break;
      }
      if(arr[i][j] == '.')
        break;
    }
    
    bestDepth = -1;
    dfs(i, j, N, M, 0);

    resetIsVisited(N, M);
    
    bestDepth = -1;
    ans = dfs(bestR, bestC, N, M, 0);
    printf("Maximum rope length is %d.\n", ans-1);
  }
  return 0;
}
