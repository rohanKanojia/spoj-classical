#include <iostream>
#include <climits>
using namespace std;

#define SIZE 100
char arr[SIZE][SIZE];
bool isVisited[SIZE][SIZE];
long long dfs(long long i, long long j, long long ROWS, long long COLS);
bool isValidCoord(long long i, long long j, long long ROWS, long long COLS);

int main() {
  long long N, M, nCase = 1;
  while(true) {
    cin >> N >> M;
    if(N == 0 && M == 0)
      break;

    for(long long i = 0; i < N; i++) {
      for(long long j = 0; j < M; j++) {
        cin >> arr[i][j];
        isVisited[i][j] = false;
      }
    }

    long long ans = 0;
    for(long long i = 0; i < N; i++) {
      for(long long j = 0; j < M; j++) {
        if(arr[i][j] == 'A')
          ans = std::max(dfs(i, j, N, M), ans);
      }
    }

    cout << "Case " << nCase++ << ": " << ans << endl;
  }
  return 0;
}

long long dfs(long long i, long long j, long long ROWS, long long COLS) {
  if(!isValidCoord(i, j, ROWS, COLS))
    return 0;
  long long rowOffsets[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  long long colOffsets[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

  isVisited[i][j] = true;
  long long maxVal = 0;
  for(long long index = 0; index < 8; index++) {
    long long curR = i + rowOffsets[index];
    long long curC = j + colOffsets[index];
    
    if(isValidCoord(curR, curC, ROWS, COLS) && !isVisited[curR][curC]) {
      if(arr[i][j]+1 == arr[curR][curC])
        maxVal = std::max(dfs(curR, curC, ROWS, COLS), maxVal);
    }
  }

  return 1+maxVal;
}

bool isValidCoord(long long i, long long j, long long ROWS, long long COLS) {
  return i >= 0 && i < ROWS && j >= 0 && j < COLS;
}
